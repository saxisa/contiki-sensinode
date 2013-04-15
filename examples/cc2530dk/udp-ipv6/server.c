#include "contiki.h"
#include "contiki-lib.h"
#include "contiki-net.h"

#include <string.h>
#include <stdlib.h>
#define DEBUG DEBUG_NONE
#include "net/uip-debug.h"
#include "dev/watchdog.h"
#include "dev/leds.h"
#include "net/rpl/rpl.h"
#include "dev/button-sensor.h"
#include "dev/adc-sensor.h"
#include "dev/sht11-sensor.h"
#include "dev/tsl2561-sensor.h"
#include "debug.h"

#define SPRINT6ADDRHALF(buf, addr) sprintf(buf, "%02x%02x:%02x%02x:%02x%02x:%02x%02x:", ((uint8_t *)addr)[0], ((uint8_t *)addr)[1], ((uint8_t *)addr)[2], ((uint8_t *)addr)[3], ((uint8_t *)addr)[4], ((uint8_t *)addr)[5], ((uint8_t *)addr)[6], ((uint8_t *)addr)[7])

#define UIP_IP_BUF   ((struct uip_ip_hdr *)&uip_buf[UIP_LLH_LEN])
#define UIP_UDP_BUF  ((struct uip_udp_hdr *)&uip_buf[uip_l2_l3_hdr_len])
static int UDP_BACKDOOR_PORT=3000;
static int TCP_HTTP_PORT=80;
#define MAX_PAYLOAD_LEN 120

static struct uip_udp_conn *server_conn;
static char buf[MAX_PAYLOAD_LEN];
static uint8_t buffer[120];
static uint16_t len;
static char hasListener = 0;
static char fullMessage = 1;
static struct etimer et;
#define SERVER_REPLY          1

static uip_ipaddr_t ipaddr;
static int listenerport;
static struct psock ps;
static struct uip_udp_conn *g_conn;

/*---------------------------------------------------------------------------*/
PROCESS(udp_server_process, "Sensor server process");
PROCESS(udp_client_process, "Sensor client process");
PROCESS(example_psock_server_process, "HTTP server");
AUTOSTART_PROCESSES(&udp_server_process, &udp_client_process,&example_psock_server_process);

static uint8_t
sprint_local_addresses(void)
{
  uint8_t i;
  uint8_t state;

  PRINTF("Server IPv6 addresses:\n");
  for(i = 0; i < UIP_DS6_ADDR_NB; i++) {
    state = uip_ds6_if.addr_list[i].state;
    if(uip_ds6_if.addr_list[i].isused && (state == ADDR_TENTATIVE || state
        == ADDR_PREFERRED)) {
      PRINTF("  ");
      PRINT6ADDR(&uip_ds6_if.addr_list[i].ipaddr);
      PRINTF("\n");
	break;
      if (state == ADDR_TENTATIVE) {
        uip_ds6_if.addr_list[i].state = ADDR_PREFERRED;
      }
    }
  }

  return i;
}
/*---------------------------------------------------------------------------*/
static PT_THREAD(handle_connection(struct psock *p))
{

PRINTF("[!!][!!]Our Debug: server.c handle_connection\n");

  PSOCK_BEGIN(p);
PRINTF("[!!][!!]server.c after begin\n");

  PSOCK_READTO(p, '\n');
  	PRINTF("[!!][!!]Our Debug: server.c get content length:%d, %s\n", PSOCK_DATALEN(p), buffer);

if (strncmp(buffer, "GET / ", 6) == 0) {
uint8_t i = sprint_local_addresses();
SPRINT6ADDRHALF(buffer, &uip_ds6_if.addr_list[i].ipaddr);
SPRINT6ADDRHALF(buffer+strlen(buffer), &uip_ds6_if.addr_list[i].ipaddr + 8);
buffer[39]='\0';
sprintf(buffer+strlen(buffer), "\"></frameset>");

PSOCK_SEND_STR(p, "HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length:139\n\n");
	  //PSOCK_SEND(p, buffer, PSOCK_DATALEN(p));
	  PSOCK_SEND_STR(p, "<frameset cols=\"*\"><frame src=\"http://[2001:da8:bf:15:212:4b00:232:1]/piserver/init?ip=");
//PSOCK_SEND_STR(p, "2001:0da8:00bf:0015:0212:4b00:0232:a255");
PSOCK_SEND_STR(p, buffer);
}
 
  PSOCK_CLOSE(p);
PRINTF("[!!][!!]Our Debug: server.c close socket\n");

  PSOCK_END(p);
}

static void
fillTempMessage(unsigned offset) {
    if (fullMessage) {
	sprintf(buf+offset, "SHT11-Temperature: %u degrees Celsius\n",
		(unsigned) (-39.60 + 0.01 * sht11_sensor.value(SHT11_SENSOR_TEMP)));
    } else {
	sprintf(buf+offset, "%u\n",
		(unsigned) (-39.60 + 0.01 * sht11_sensor.value(SHT11_SENSOR_TEMP)));	
    }
}

static void
fillHumidityMessage(unsigned offset) {
  unsigned rh;
  rh = sht11_sensor.value(SHT11_SENSOR_HUMIDITY);
  if (fullMessage) {
    	sprintf(buf+offset, "SHT11-Rel. humidity: %u%%\n",
		(unsigned) (-4 + 0.0405*rh - 2.8e-6*(rh*rh)));
  } else {
  	sprintf(buf+offset, "%u\n",
		(unsigned) (-4 + 0.0405*rh - 2.8e-6*(rh*rh)));
  }
}

static void
fillLightMessage(unsigned offset) {
    if (fullMessage) {
	sprintf(buf+offset, "TSL2561-Illumination: %d lux\n", tsl2561_sensor.value(TSL2561_SENSOR_ILLUMINATION));
    } else {
        sprintf(buf+offset, "%d\n", tsl2561_sensor.value(TSL2561_SENSOR_ILLUMINATION));
    }
}

static void
fillChipTempMessage(unsigned offset) {
  static int rv;
  static float sane = 0;
  static int dec;
  static float frac;
  rv = adc_sensor.value(ADC_SENSOR_TYPE_TEMP);
      sane = 25 + ((rv - 1480) / 4.5);
      dec = sane;
      frac = sane - dec;
  if (fullMessage) {
      sprintf(buf+offset, "ADC-Temp=%d.%02u C (%d)\n", dec, (unsigned int)(frac*100), rv);
  } else {
      sprintf(buf+offset, "%d.%02u\n", dec, (unsigned int)(frac*100));
  }
}

static void
fillVDDMessage(unsigned offset) {
  static int rv;
  static float sane = 0;
  static int dec;
  static float frac;
  rv = adc_sensor.value(ADC_SENSOR_TYPE_VDD);
  sane = rv * 3.75 / 2047;
  dec = sane;
  frac = sane - dec;
  if (fullMessage) {
      sprintf(buf+offset, "ADC-Supply=%d.%02u V (%d)\n", dec, (unsigned int)(frac*100), rv);
  } else {
      sprintf(buf+offset, "%d.%02u\n", dec, (unsigned int)(frac*100));
  }
}

static void
fillRawData() {
  fullMessage = 0;
  fillTempMessage(0);
  fillHumidityMessage(strlen(buf));
  fillLightMessage(strlen(buf));
  fillChipTempMessage(strlen(buf));
  fillVDDMessage(strlen(buf));
  fullMessage = 1;
}

extern int inet_pton6(const char *src, unsigned char *dst);

static void setListener() {
    static char temp[16];
	static char *addr_begin, *addr_end;
    char succ;
    int port = 0;
	addr_begin = strchr(buf, ' ') + 1;
	addr_end = strchr(addr_begin, ' ');
    
    *addr_end = '\0';
    port = atoi(addr_end + 1);
	succ = inet_pton6(addr_begin, temp);
	if (succ == 0) {
		sprintf(buf, "Set Failed!\n");
		return;
    }
	
	uip_ip6addr_u8(&ipaddr, temp[0], temp[1], temp[2], temp[3], 
			temp[4], temp[5], temp[6], temp[7], 
			temp[8], temp[9], temp[10], temp[11], 
			temp[12], temp[13], temp[14], temp[15]);
    printf("Set listener: ");
	PRINT6ADDR(&ipaddr);
    printf(", port: %d\n", port);
	g_conn = udp_new(&ipaddr, UIP_HTONS(port), NULL);
	if(!g_conn) {
	    PRINTF("udp_new g_conn error.\n");
	}
	listenerport = port;
	// udp_bind(g_conn, UIP_HTONS(GLOBAL_CONN_PORT));
	sprintf(buf, "Set Successfully!\n");
	hasListener = 1;
        leds_on(LEDS_YELLOW);
}

static void
tcpip_handler(void)
{
  memset(buf, 0, MAX_PAYLOAD_LEN);
    leds_on(LEDS_GREEN);
    len = uip_datalen();
    memcpy(buf, uip_appdata, len);
    PRINTF("%u bytes from [", len);
    PRINT6ADDR(&UIP_IP_BUF->srcipaddr);
    PRINTF("]:%u\n", UIP_HTONS(UIP_UDP_BUF->srcport));
    PRINTF("%s\n", buf);
#if SERVER_REPLY
    uip_ipaddr_copy(&server_conn->ripaddr, &UIP_IP_BUF->srcipaddr);
    server_conn->rport = UIP_UDP_BUF->srcport;
    if (strncmp(buf, "temp", 4) == 0) {
		fillTempMessage(0);
    } else if (strncmp(buf, "humi", 4) == 0) {
		fillHumidityMessage(0);
    } else if (strncmp(buf, "chiptemp", 4) == 0) {
		fillChipTempMessage(0);
    } else if (strncmp(buf, "vdd", 3)==0) {
        fillVDDMessage(0);
    } else if (strncmp(buf, "light", 5) == 0) {
		fillLightMessage(0);
    } else if (strncmp(buf, "rawdata", 7) == 0) {
		fillRawData();
    } else if (strncmp(buf, "setlistener ", 12) == 0) {
		setListener();
    } else if (strncmp(buf, "getlistener", 11) == 0) {
	if (hasListener) {
		SPRINT6ADDRHALF(buf, &ipaddr);
		SPRINT6ADDRHALF(buf+strlen(buf), &ipaddr + 8);
		buf[39]=' ';
		sprintf(buf+40, "%d\n", listenerport);
	} else {
		sprintf(buf, "N/A\n");
	}
    } else if (strncmp(buf, "removelistener", 14) == 0) {
		hasListener = 0;
		sprintf(buf, "Remove Successfully!\n");
	        leds_off(LEDS_YELLOW);
    } else if (strncmp(buf, "setinterval ", 12) == 0) {
	  int interval = 0;
	  interval = atoi(buf + 12);
	  if (interval == 0) {
	    	sprintf(buf, "Interval Set Failed!\n");
	  } else {
	  	etimer_set(&et, interval * CLOCK_SECOND);
    	  	sprintf(buf, "Interval Set Successfully!\n");
 	  }
    } else {
	sprintf(buf, "Unrecognized Command!\ntemp/humi/chiptemp/vdd/light/rawdata/setlistener addr6 port/removelistener/setinterval seconds\n");
    }
    uip_udp_packet_send(server_conn, buf, strlen(buf));
//    uip_udp_packet_send(server_conn, buf, len);
    /* Restore server connection to allow data from any node */
    uip_create_unspecified(&server_conn->ripaddr);
    server_conn->rport = 0;
#endif
  leds_off(LEDS_GREEN);
  return;
}

/*---------------------------------------------------------------------------*/

PROCESS_THREAD(udp_client_process, ev, data)
{
  PROCESS_BEGIN();
  etimer_set(&et, 5 * CLOCK_SECOND);

  while(1) {
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    if (hasListener) {
	leds_on(LEDS_GREEN);
	printf("sending data...\n");
	fillRawData();
	uip_udp_packet_send(g_conn, buf, strlen(buf));
        leds_off(LEDS_GREEN);
    }
    etimer_reset(&et);
  }
  PROCESS_END();
}

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(udp_server_process, ev, data)
{

  PROCESS_BEGIN();
  putstring("Starting UDP server\n");

  server_conn = udp_new(NULL, UIP_HTONS(0), NULL);
  udp_bind(server_conn, UIP_HTONS(UDP_BACKDOOR_PORT));

  SENSORS_ACTIVATE(tsl2561_sensor);
  SENSORS_ACTIVATE(sht11_sensor);
  SENSORS_ACTIVATE(adc_sensor);

  PRINTF("Listen port: %d, TTL=%u\n", UDP_BACKDOOR_PORT, server_conn->ttl);

  while(1) {
    putstring("[][]WAITING UDP\n");
    PROCESS_YIELD();
    PRINTF("Udp Port tcpip_event, %d\n", uip_udp_conn->lport);
    if(ev == tcpip_event && uip_newdata() && uip_udp_conn->lport == UIP_HTONS(UDP_BACKDOOR_PORT)) {
      PRINTF("Udp Port tcpip_event\n");
      tcpip_handler();
    }
  }
  PROCESS_END();
}

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(example_psock_server_process, ev, data)
{
  /*
   * The process begins here.
   */
  PROCESS_BEGIN();
  putstring("Starting TCP server\n");
  /*
   * We start with setting up a listening TCP port. Note how we're
   * using the HTONS() macro to convert the port number (12345) to
   * network byte order as required by the tcp_listen() function.
   */
  tcp_listen(UIP_HTONS(TCP_HTTP_PORT));
  PRINTF("Listen port: %d\n", TCP_HTTP_PORT);

  /*
   * We loop for ever, accepting new connections.
   */
  while(1) {

    /*
     * We wait until we get the first TCP/IP event, which probably
     * comes because someone connected to us.
     */
    putstring("[][]WAITING TCP\n");
    PROCESS_WAIT_EVENT_UNTIL(ev == tcpip_event && uip_conn->lport == UIP_HTONS(TCP_HTTP_PORT));
    /*
     * If a peer connected with us, we'll initialize the protosocket
     * with PSOCK_INIT().
     */
    if(uip_connected()) {
      
      /*
       * The PSOCK_INIT() function initializes the protosocket and
       * binds the input buffer to the protosocket.
       */
putstring("[][]Our Debug: server.c uip_connected\n");
      PSOCK_INIT(&ps, buffer, sizeof(buffer));

      /*
       * We loop until the connection is aborted, closed, or times out.
       */
      while(!(uip_aborted() || uip_closed() || uip_timedout())) {
putstring("[!!][!!]Our Debug: server.c in while loop\n");
        /*
         * We wait until we get a TCP/IP event. Remember that we
         * always need to wait for events inside a process, to let
         * other processes run while we are waiting.
         */

        /*
         * Here is where the real work is taking place: we call the
         * handle_connection() protothread that we defined above. This
         * protothread uses the protosocket to receive the data that
         * we want it to.
         */
        handle_connection(&ps);
        PROCESS_WAIT_EVENT_UNTIL(ev == tcpip_event && uip_conn->lport == UIP_HTONS(TCP_HTTP_PORT));
	putstring("[!!][!!]Our Debug: server.c tcpip_event\n");
      }
    }
  }
  
  /*
   * We must always declare the end of a process.
   */
  PROCESS_END();
}

