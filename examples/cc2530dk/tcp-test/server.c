/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

#include "contiki-net.h"

#include <string.h>

#define DEBUG DEBUG_PRINT
#include "net/uip-debug.h"

#include "debug.h"
/*
 * We define one protosocket since we've decided to only handle one
 * connection at a time. If we want to be able to handle more than one
 * connection at a time, each parallell connection needs its own
 * protosocket.
 */

static struct psock ps;
/*
 * We must have somewhere to put incoming data, and we use a 50 byte
 * buffer for this purpose.
 */
static uint8_t buffer[50];

/*---------------------------------------------------------------------------*/
/*
 * A protosocket always requires a protothread. The protothread
 * contains the code that uses the protosocket. We define the
 * protothread here.
 */
static PT_THREAD(handle_connection(struct psock *p))
{

PRINTF("[!!][!!]Our Debug: server.c handle_connection\n");
  /*
   * A protosocket's protothread must start with a PSOCK_BEGIN(), with
   * the protosocket as argument.
   *
   * Remember that the same rules as for protothreads apply: do NOT
   * use local variables unless you are very sure what you are doing!
   * Local (stack) variables are not preserved when the protothread
   * blocks.
   */
  PSOCK_BEGIN(p);
PRINTF("[!!][!!]server.c after begin\n");
  /*
   * We start by sending out a welcoming message. The message is sent
   * using the PSOCK_SEND_STR() function that sends a null-terminated
   * string.
   */
  PSOCK_SEND_STR(p, "Welcome, please type something and press return.\n");
PRINTF("[!!][!!]Our Debug: server.c after welcome");
  /*
   * Next, we use the PSOCK_READTO() function to read incoming data
   * from the TCP connection until we get a newline character. The
   * number of bytes that we actually keep is dependant of the length
   * of the input buffer that we use. Since we only have a 10 byte
   * buffer here (the buffer[] array), we can only remember the first
   * 10 bytes received. The rest of the line up to the newline simply
   * is discarded.
   */
  PSOCK_READTO(p, '\n');
  	PRINTF("[!!][!!]Our Debug: server.c get content %d, %d, length:%d\n", buffer[0], buffer[1], PSOCK_DATALEN(p));
  /*
   * And we send back the contents of the buffer. The PSOCK_DATALEN()
   * function provides us with the length of the data that we've
   * received. Note that this length will not be longer than the input
   * buffer we're using.
   */
  PSOCK_SEND_STR(p, "Got the following data: ");
  PSOCK_SEND(p, buffer, PSOCK_DATALEN(p));

  PSOCK_SEND_STR(p, "Good bye!\r\n");

  /*
   * We close the protosocket.
   */
  PSOCK_CLOSE(p);

  /*
   * And end the protosocket's protothread.
   */
  PSOCK_END(p);
}
/*---------------------------------------------------------------------------*/
/*
 * We declare the process.
 */
PROCESS(example_psock_server_process, "Example protosocket server");
AUTOSTART_PROCESSES(&example_psock_server_process);
/*---------------------------------------------------------------------------*/
/*
 * The definition of the process.
 */
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
  tcp_listen(UIP_HTONS(3000));
putstring("Listen port: 3000\n");
  /*
   * We loop for ever, accepting new connections.
   */
  while(1) {

    /*
     * We wait until we get the first TCP/IP event, which probably
     * comes because someone connected to us.
     */

PROCESS_WAIT_EVENT_UNTIL(ev == tcpip_event);
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
        PROCESS_WAIT_EVENT_UNTIL(ev == tcpip_event);
	putstring("[!!][!!]Our Debug: server.c tcpip_event\n");
        /*
         * Here is where the real work is taking place: we call the
         * handle_connection() protothread that we defined above. This
         * protothread uses the protosocket to receive the data that
         * we want it to.
         */
        handle_connection(&ps);
      }
    }
  }
  
  /*
   * We must always declare the end of a process.
   */
  PROCESS_END();
}

/*---------------------------------------------------------------------------*/
