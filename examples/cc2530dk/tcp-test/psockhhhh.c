# 1 "../../../core/net/psock.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "../../../core/net/psock.c"
# 35 "../../../core/net/psock.c"
# 1 "/usr/local/bin/../share/sdcc/include/string.h" 1 3 4
# 39 "/usr/local/bin/../share/sdcc/include/string.h" 3 4
  typedef unsigned int size_t;
# 51 "/usr/local/bin/../share/sdcc/include/string.h" 3 4
extern void *memcpy (void * dest, const void * src, size_t n);
extern void *memmove (void *dest, const void *src, size_t n);
extern char *strcpy (char * dest, const char * src);
extern char *strncpy(char * dest, const char * src, size_t n);


extern char *strcat (char * dest, const char * src);
extern char *strncat(char * dest, const char * src, size_t n);


extern int memcmp (const void *s1, const void *s2, size_t n);
extern int strcmp (const char *s1, const char *s2);


extern int strncmp(const char *s1, const char *s2, size_t n);
extern size_t strxfrm(char *dest, const char *src, size_t n);


extern void *memchr (const void *s, int c, size_t n);

extern char *strchr (const char *s, char c);



extern size_t strcspn(const char *s, const char *reject);
extern char *strpbrk(const char *s, const char *accept);

extern char *strrchr(const char *s, char c);



extern size_t strspn (const char *s, const char *accept);
extern char *strstr (const char *haystack, const char *needle);
extern char *strtok (char * str, const char * delim);



extern void *memset (void *s, unsigned char c, size_t n);





extern size_t strlen (const char *s);
# 36 "../../../core/net/psock.c" 2

# 1 "../../../core/./net/psock.h" 1
# 89 "../../../core/./net/psock.h"
# 1 "../../../core/./contiki.h" 1
# 37 "../../../core/./contiki.h"
# 1 "../../../core/./contiki-version.h" 1
# 38 "../../../core/./contiki.h" 2
# 1 "../../../platform/cc2530dk/./contiki-conf.h" 1



# 1 "../../../cpu/cc253x/./8051def.h" 1
# 15 "../../../cpu/cc253x/./8051def.h"
# 1 "/usr/local/bin/../share/sdcc/include/stdint.h" 1 3 4
# 43 "/usr/local/bin/../share/sdcc/include/stdint.h" 3 4
typedef signed char int8_t;
typedef short int int16_t;
typedef long int int32_t;





typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;







typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef long int int_least32_t;





typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned long int uint_least32_t;







typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef long int int_fast32_t;





typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;






  typedef long int intptr_t;
  typedef unsigned long int uintptr_t;







typedef long int intmax_t;
typedef unsigned long int uintmax_t;
# 16 "../../../cpu/cc253x/./8051def.h" 2



# 1 "../../../core/./dev/watchdog.h" 1
# 35 "../../../core/./dev/watchdog.h"
void watchdog_init(void);
void watchdog_start(void);
void watchdog_periodic(void);
void watchdog_stop(void);

void watchdog_reboot(void);
# 20 "../../../cpu/cc253x/./8051def.h" 2
# 80 "../../../cpu/cc253x/./8051def.h"
typedef unsigned short uip_stats_t;


typedef unsigned short clock_time_t;
# 5 "../../../platform/cc2530dk/./contiki-conf.h" 2
# 1 "../../../core/./sys/cc.h" 1
# 47 "../../../core/./sys/cc.h"
# 1 "../../../platform/cc2530dk/./contiki-conf.h" 1
# 48 "../../../core/./sys/cc.h" 2
# 6 "../../../platform/cc2530dk/./contiki-conf.h" 2




# 1 "./project-conf.h" 1
# 11 "../../../platform/cc2530dk/./contiki-conf.h" 2


# 1 "../../../platform/cc2530dk/./models.h" 1
# 14 "../../../platform/cc2530dk/./contiki-conf.h" 2
# 39 "../../../core/./contiki.h" 2

# 1 "../../../core/./sys/process.h" 1
# 56 "../../../core/./sys/process.h"
# 1 "../../../core/./sys/pt.h" 1
# 51 "../../../core/./sys/pt.h"
# 1 "../../../core/./sys/lc.h" 1
# 124 "../../../core/./sys/lc.h"
# 1 "../../../core/./sys/lc-switch.h" 1
# 63 "../../../core/./sys/lc-switch.h"
typedef unsigned short lc_t;
# 125 "../../../core/./sys/lc.h" 2
# 52 "../../../core/./sys/pt.h" 2

struct pt {
  lc_t lc;
};
# 57 "../../../core/./sys/process.h" 2


typedef unsigned char process_event_t;
typedef void * process_data_t;
typedef unsigned char process_num_events_t;
# 315 "../../../core/./sys/process.h"
struct process {
  struct process *next;






  char (* thread)(struct pt *, process_event_t, process_data_t);
  struct pt pt;
  unsigned char state, needspoll;
};
# 342 "../../../core/./sys/process.h"
 void process_start(struct process *p, const char *arg);
# 365 "../../../core/./sys/process.h"
 int process_post(struct process *p, process_event_t ev, void* data);
# 377 "../../../core/./sys/process.h"
 void process_post_synch(struct process *p,
        process_event_t ev, void* data);
# 390 "../../../core/./sys/process.h"
 void process_exit(struct process *p);
# 403 "../../../core/./sys/process.h"
 extern struct process *process_current;
# 453 "../../../core/./sys/process.h"
 process_event_t process_alloc_event(void);
# 470 "../../../core/./sys/process.h"
 void process_poll(struct process *p);
# 485 "../../../core/./sys/process.h"
void process_init(void);
# 500 "../../../core/./sys/process.h"
int process_run(void);
# 512 "../../../core/./sys/process.h"
 int process_is_running(struct process *p);







int process_nevents(void);



 extern struct process *process_list;
# 41 "../../../core/./contiki.h" 2
# 1 "../../../core/./sys/autostart.h" 1
# 43 "../../../core/./sys/autostart.h"
# 1 "../../../core/./sys/process.h" 1
# 44 "../../../core/./sys/autostart.h" 2
# 57 "../../../core/./sys/autostart.h"
 extern struct process * const autostart_processes[];

void autostart_start(struct process * const processes[]);
void autostart_exit(struct process * const processes[]);
# 42 "../../../core/./contiki.h" 2

# 1 "../../../core/./sys/timer.h" 1
# 76 "../../../core/./sys/timer.h"
# 1 "../../../core/./sys/clock.h" 1
# 91 "../../../core/./sys/clock.h"
void clock_init(void);
# 100 "../../../core/./sys/clock.h"
 clock_time_t clock_time(void);
# 110 "../../../core/./sys/clock.h"
 unsigned long clock_seconds(void);






void clock_set_seconds(unsigned long sec);






void clock_wait(clock_time_t t);







void clock_delay_usec(uint16_t dt);





int clock_fine_max(void);
unsigned short clock_fine(void);
void clock_delay_usec(unsigned int delay);
# 77 "../../../core/./sys/timer.h" 2
# 86 "../../../core/./sys/timer.h"
struct timer {
  clock_time_t start;
  clock_time_t interval;
};

void timer_set(struct timer *t, clock_time_t interval);
void timer_reset(struct timer *t);
void timer_restart(struct timer *t);
int timer_expired(struct timer *t);
clock_time_t timer_remaining(struct timer *t);
# 44 "../../../core/./contiki.h" 2
# 1 "../../../core/./sys/ctimer.h" 1
# 57 "../../../core/./sys/ctimer.h"
# 1 "../../../core/./sys/etimer.h" 1
# 65 "../../../core/./sys/etimer.h"
# 1 "../../../core/./sys/timer.h" 1
# 66 "../../../core/./sys/etimer.h" 2
# 76 "../../../core/./sys/etimer.h"
struct etimer {
  struct timer timer;
  struct etimer *next;
  struct process *p;
};
# 98 "../../../core/./sys/etimer.h"
 void etimer_set(struct etimer *et, clock_time_t interval);
# 115 "../../../core/./sys/etimer.h"
 void etimer_reset(struct etimer *et);
# 132 "../../../core/./sys/etimer.h"
void etimer_restart(struct etimer *et);
# 154 "../../../core/./sys/etimer.h"
void etimer_adjust(struct etimer *et, int td);
# 163 "../../../core/./sys/etimer.h"
clock_time_t etimer_expiration_time(struct etimer *et);
# 173 "../../../core/./sys/etimer.h"
clock_time_t etimer_start_time(struct etimer *et);
# 183 "../../../core/./sys/etimer.h"
 int etimer_expired(struct etimer *et);
# 195 "../../../core/./sys/etimer.h"
void etimer_stop(struct etimer *et);
# 212 "../../../core/./sys/etimer.h"
void etimer_request_poll(void);
# 222 "../../../core/./sys/etimer.h"
int etimer_pending(void);
# 233 "../../../core/./sys/etimer.h"
clock_time_t etimer_next_expiration_time(void);




extern struct process etimer_process;
# 58 "../../../core/./sys/ctimer.h" 2

struct ctimer {
  struct ctimer *next;
  struct etimer etimer;
  struct process *p;
  void (*f)(void *);
  void *ptr;
};
# 82 "../../../core/./sys/ctimer.h"
void ctimer_reset(struct ctimer *c);
# 99 "../../../core/./sys/ctimer.h"
void ctimer_restart(struct ctimer *c);
# 113 "../../../core/./sys/ctimer.h"
void ctimer_set(struct ctimer *c, clock_time_t t,
  void (*f)(void *), void *ptr);
# 126 "../../../core/./sys/ctimer.h"
void ctimer_stop(struct ctimer *c);
# 136 "../../../core/./sys/ctimer.h"
int ctimer_expired(struct ctimer *c);







void ctimer_init(void);
# 45 "../../../core/./contiki.h" 2
# 1 "../../../core/./sys/etimer.h" 1
# 46 "../../../core/./contiki.h" 2
# 1 "../../../core/./sys/rtimer.h" 1
# 58 "../../../core/./sys/rtimer.h"
typedef unsigned short rtimer_clock_t;



# 1 "../../../cpu/cc253x/./rtimer-arch.h" 1
# 48 "../../../cpu/cc253x/./rtimer-arch.h"
# 1 "../../../cpu/cc253x/./cc253x.h" 1
# 50 "../../../cpu/cc253x/./cc253x.h"
# 1 "/usr/local/bin/../share/sdcc/include/mcs51/compiler.h" 1 3 4
# 51 "../../../cpu/cc253x/./cc253x.h" 2
# 78 "../../../cpu/cc253x/./cc253x.h"
__sfr __at(0x80) P0;
  __sbit __at(0x80 +7) P0_7;
  __sbit __at(0x80 +6) P0_6;
  __sbit __at(0x80 +5) P0_5;
  __sbit __at(0x80 +4) P0_4;
  __sbit __at(0x80 +3) P0_3;
  __sbit __at(0x80 +2) P0_2;
  __sbit __at(0x80 +1) P0_1;
  __sbit __at(0x80 +0) P0_0;
__sfr __at(0x81) SP;
__sfr __at(0x82) DPL0;
__sfr __at(0x83) DPH0;
__sfr __at(0x84) DPL1;
__sfr __at(0x85) DPH1;
__sfr __at(0x87) PCON;
__sfr __at(0x88) TCON;
  __sbit __at(0x88 +7) URX1IF;
  __sbit __at(0x88 +5) ADCIF;
  __sbit __at(0x88 +3) URX0IF;
  __sbit __at(0x88 +2) IT1;
  __sbit __at(0x88 +1) RFERRIF;
  __sbit __at(0x88 +0) IT0;
__sfr __at(0x90) P1;
  __sbit __at(0x90 +7) P1_7;
  __sbit __at(0x90 +6) P1_6;
  __sbit __at(0x90 +5) P1_5;
  __sbit __at(0x90 +4) P1_4;
  __sbit __at(0x90 +3) P1_3;
  __sbit __at(0x90 +2) P1_2;
  __sbit __at(0x90 +1) P1_1;
  __sbit __at(0x90 +0) P1_0;
__sfr __at(0x92) DPS;
__sfr __at(0x98) S0CON;
  __sbit __at(0x98 +1) ENCIF_1;
  __sbit __at(0x98 +0) ENCIF_0;
__sfr __at(0x9A) IEN2;
__sfr __at(0x9B) S1CON;
__sfr __at(0xA0) P2;
  __sbit __at(0xA0 +7) P2_7;
  __sbit __at(0xA0 +6) P2_6;
  __sbit __at(0xA0 +5) P2_5;
  __sbit __at(0xA0 +4) P2_4;
  __sbit __at(0xA0 +3) P2_3;
  __sbit __at(0xA0 +2) P2_2;
  __sbit __at(0xA0 +1) P2_1;
  __sbit __at(0xA0 +0) P2_0;
__sfr __at(0xA8) IEN0;
  __sbit __at(0xA8 +7) EA;
  __sbit __at(0xA8 +5) STIE;
  __sbit __at(0xA8 +4) ENCIE;
  __sbit __at(0xA8 +3) URX1IE;
  __sbit __at(0xA8 +2) URX0IE;
  __sbit __at(0xA8 +1) ADCIE;
  __sbit __at(0xA8 +0) RFERRIE;
__sfr __at(0xA9) IP0;
__sfr __at(0xB8) IEN1;
  __sbit __at(0xB8 +5) P0IE;
  __sbit __at(0xB8 +4) T4IE;
  __sbit __at(0xB8 +3) T3IE;
  __sbit __at(0xB8 +2) T2IE;
  __sbit __at(0xB8 +1) T1IE;
  __sbit __at(0xB8 +0) DMAIE;
__sfr __at(0xB9) IP1;
__sfr __at(0xC0) IRCON;
  __sbit __at(0xC0 +7) STIF;
  __sbit __at(0xC0 +5) P0IF;
  __sbit __at(0xC0 +4) T4IF;
  __sbit __at(0xC0 +3) T3IF;
  __sbit __at(0xC0 +2) T2IF;
  __sbit __at(0xC0 +1) T1IF;
  __sbit __at(0xC0 +0) DMAIF;
__sfr __at(0xD0) PSW;
  __sbit __at(0xD0 +7) CY;
  __sbit __at(0xD0 +6) AC;
  __sbit __at(0xD0 +5) F0;
  __sbit __at(0xD0 +4) RS1;
  __sbit __at(0xD0 +3) RS0;
  __sbit __at(0xD0 +2) OV;
  __sbit __at(0xD0 +1) F1;
  __sbit __at(0xD0 +0) P;
__sfr __at(0xE0) ACC;
  __sbit __at(0xE0 +7) ACC_7;
  __sbit __at(0xE0 +6) ACC_6;
  __sbit __at(0xE0 +5) ACC_5;
  __sbit __at(0xE0 +4) ACC_4;
  __sbit __at(0xE0 +3) ACC_3;
  __sbit __at(0xE0 +2) ACC_2;
  __sbit __at(0xE0 +1) ACC_1;
  __sbit __at(0xE0 +0) ACC_0;
__sfr __at(0xE8) IRCON2;
  __sbit __at(0xE8 +4) WDTIF;
  __sbit __at(0xE8 +3) P1IF;
  __sbit __at(0xE8 +2) UTX1IF;
  __sbit __at(0xE8 +1) UTX0IF;
  __sbit __at(0xE8 +0) P2IF;
__sfr __at(0xF0) B;
  __sbit __at(0xF0 +7) B_7;
  __sbit __at(0xF0 +6) B_6;
  __sbit __at(0xF0 +5) B_5;
  __sbit __at(0xF0 +4) B_4;
  __sbit __at(0xF0 +3) B_3;
  __sbit __at(0xF0 +2) B_2;
  __sbit __at(0xF0 +1) B_1;
  __sbit __at(0xF0 +0) B_0;


__sfr __at(0xB4) ADCCON1;
__sfr __at(0xB5) ADCCON2;
__sfr __at(0xB6) ADCCON3;
__sfr __at(0xBA) ADCL;
__sfr __at(0xBB) ADCH;
__sfr __at(0xBC) RNDL;
__sfr __at(0xBD) RNDH;


__sfr __at(0xB1) ENCDI;
__sfr __at(0xB2) ENCDO;
__sfr __at(0xB3) ENCCS;


__sfr __at(0xD1) DMAIRQ;
__sfr __at(0xD2) DMA1CFGL;
__sfr __at(0xD3) DMA1CFGH;
__sfr __at(0xD4) DMA0CFGL;
__sfr __at(0xD5) DMA0CFGH;
__sfr __at(0xD6) DMAARM;
__sfr __at(0xD7) DMAREQ;


__sfr __at(0x89) P0IFG;
__sfr __at(0x8A) P1IFG;
__sfr __at(0x8B) P2IFG;
__sfr __at(0x8C) PICTL;
__sfr __at(0xAB) P0IEN;
__sfr __at(0x8D) P1IEN;
__sfr __at(0xAC) P2IEN;
__sfr __at(0x8F) P0INP;
__sfr __at(0xF1) PERCFG;
__sfr __at(0xF2) APCFG;
__sfr __at(0xF3) P0SEL;
__sfr __at(0xF4) P1SEL;
__sfr __at(0xF5) P2SEL;
__sfr __at(0xF6) P1INP;
__sfr __at(0xF7) P2INP;
__sfr __at(0xFD) P0DIR;
__sfr __at(0xFE) P1DIR;
__sfr __at(0xFF) P2DIR;
__sfr __at(0xAE) PMUX;


__sfr __at(0x93) MPAGE;
__sfr __at(0x93) _XPAGE;
__sfr __at(0xC7) MEMCTR;
__sfr __at(0x9F) FMAP;
__sfr __at(0x9F) PSBANK;


__sfr __at(0x91) RFIRQF1;
__sfr __at(0xD9) RFD;
__sfr __at(0xE1) RFST;
__sfr __at(0xE9) RFIRQF0;
__sfr __at(0xBF) RFERRF;


__sfr __at(0x95) ST0;
__sfr __at(0x96) ST1;
__sfr __at(0x97) ST2;
__sfr __at(0xAD) STLOAD;
__sfr __at(0xBE) SLEEPCMD;
__sfr __at(0x9D) SLEEPSTA;


__sfr __at(0xC6) CLKCONCMD;
__sfr __at(0x9E) CLKCONSTA;


__sfr __at(0xDA) T1CC0L;
__sfr __at(0xDB) T1CC0H;
__sfr __at(0xDC) T1CC1L;
__sfr __at(0xDD) T1CC1H;
__sfr __at(0xDE) T1CC2L;
__sfr __at(0xDF) T1CC2H;
__sfr __at(0xE2) T1CNTL;
__sfr __at(0xE3) T1CNTH;
__sfr __at(0xE4) T1CTL;
__sfr __at(0xE5) T1CCTL0;
__sfr __at(0xE6) T1CCTL1;
__sfr __at(0xE7) T1CCTL2;
__sfr __at(0xAF) T1STAT;


__sfr __at(0x94) T2CTRL;
__sfr __at(0x9C) T2EVTCFG;
__sfr __at(0xA1) T2IRQF;
__sfr __at(0xA2) T2M0;
__sfr __at(0xA3) T2M1;
__sfr __at(0xA4) T2MOVF0;
__sfr __at(0xA5) T2MOVF1;
__sfr __at(0xA6) T2MOVF2;
__sfr __at(0xA7) T2IRQM;
__sfr __at(0xC3) T2MSEL;


__sfr __at(0xCA) T3CNT;
__sfr __at(0xCB) T3CTL;
__sfr __at(0xCC) T3CCTL0;
__sfr __at(0xCD) T3CC0;
__sfr __at(0xCE) T3CCTL1;
__sfr __at(0xCF) T3CC1;


__sfr __at(0xEA) T4CNT;
__sfr __at(0xEB) T4CTL;
__sfr __at(0xEC) T4CCTL0;
__sfr __at(0xED) T4CC0;
__sfr __at(0xEE) T4CCTL1;
__sfr __at(0xEF) T4CC1;


__sfr __at(0xD8) TIMIF;
  __sbit __at(0xD8 +6) OVFIM;
  __sbit __at(0xD8 +5) T4CH1IF;
  __sbit __at(0xD8 +4) T4CH0IF;
  __sbit __at(0xD8 +3) T4OVFIF;
  __sbit __at(0xD8 +2) T3CH1IF;
  __sbit __at(0xD8 +1) T3CH0IF;
  __sbit __at(0xD8 +0) T3OVFIF;


__sfr __at(0x86) U0CSR;
__sfr __at(0xC1) U0DBUF;
__sfr __at(0xC2) U0BAUD;
__sfr __at(0xC4) U0UCR;
__sfr __at(0xC5) U0GCR;


__sfr __at(0xF8) U1CSR;
  __sbit __at(0xF8 +7) MODE;
  __sbit __at(0xF8 +6) RE;
  __sbit __at(0xF8 +5) SLAVE;
  __sbit __at(0xF8 +4) FE;
  __sbit __at(0xF8 +3) ERR;
  __sbit __at(0xF8 +2) RX_BYTE;
  __sbit __at(0xF8 +1) TX_BYTE;
  __sbit __at(0xF8 +0) ACTIVE;
__sfr __at(0xF9) U1DBUF;
__sfr __at(0xFA) U1BAUD;
__sfr __at(0xFB) U1UCR;
__sfr __at(0xFC) U1GCR;


__sfr __at(0xC9) WDCTL;




__xdata volatile unsigned char __at(0x61A6) MONMUX;
__xdata volatile unsigned char __at(0x61A6) OPAMPMC;

__xdata volatile unsigned char __at(0x6230) I2CCFG;
__xdata volatile unsigned char __at(0x6231) I2CSTAT;
__xdata volatile unsigned char __at(0x6232) I2CDATA;
__xdata volatile unsigned char __at(0x6233) I2CADDR;
__xdata volatile unsigned char __at(0x6234) I2CWC;
__xdata volatile unsigned char __at(0x6235) I2CIO;

__xdata volatile unsigned char __at(0x6243) OBSSEL0;
__xdata volatile unsigned char __at(0x6244) OBSSEL1;
__xdata volatile unsigned char __at(0x6245) OBSSEL2;
__xdata volatile unsigned char __at(0x6246) OBSSEL3;
__xdata volatile unsigned char __at(0x6247) OBSSEL4;
__xdata volatile unsigned char __at(0x6248) OBSSEL5;
__xdata volatile unsigned char __at(0x6249) CHVER;
__xdata volatile unsigned char __at(0x624A) CHIPID;



__xdata volatile unsigned char __at(0x624B) TESTREG0;

__xdata volatile unsigned char __at(0x6260) DBGDATA;
__xdata volatile unsigned char __at(0x6262) SRCRC;
__xdata volatile unsigned char __at(0x6264) BATTMON;
__xdata volatile unsigned char __at(0x6265) IVCTRL;
__xdata volatile unsigned char __at(0x6270) FCTL;
__xdata volatile unsigned char __at(0x6271) FADDRL;
__xdata volatile unsigned char __at(0x6272) FADDRH;
__xdata volatile unsigned char __at(0x6273) FWDATA;
__xdata volatile unsigned char __at(0x6276) CHIPINFO0;
__xdata volatile unsigned char __at(0x6277) CHIPINFO1;
__xdata volatile unsigned char __at(0x6281) IRCTL;
__xdata volatile unsigned char __at(0x6290) CLD;
__xdata volatile unsigned char __at(0x62A0) XX_T1CCTL0;
__xdata volatile unsigned char __at(0x62A1) XX_T1CCTL1;
__xdata volatile unsigned char __at(0x62A2) XX_T1CCTL2;
__xdata volatile unsigned char __at(0x62A3) T1CCTL3;
__xdata volatile unsigned char __at(0x62A4) T1CCTL4;
__xdata volatile unsigned char __at(0x62A6) XX_T1CC0L;
__xdata volatile unsigned char __at(0x62A7) XX_T1CC0H;
__xdata volatile unsigned char __at(0x62A8) XX_T1CC1L;
__xdata volatile unsigned char __at(0x62A9) XX_T1CC1H;
__xdata volatile unsigned char __at(0x62AA) XX_T1CC2L;
__xdata volatile unsigned char __at(0x62AB) XX_T1CC2H;
__xdata volatile unsigned char __at(0x62AC) T1CC3L;
__xdata volatile unsigned char __at(0x62AD) T1CC3H;
__xdata volatile unsigned char __at(0x62AE) T1CC4L;
__xdata volatile unsigned char __at(0x62AF) T1CC4H;
__xdata volatile unsigned char __at(0x62B0) STCC;
__xdata volatile unsigned char __at(0x62B1) STCS;
__xdata volatile unsigned char __at(0x62B2) STCV0;
__xdata volatile unsigned char __at(0x62B3) STCV1;
__xdata volatile unsigned char __at(0x62B4) STCV2;
__xdata volatile unsigned char __at(0x62C0) OPAMPC;
__xdata volatile unsigned char __at(0x62C1) OPAMPS;
__xdata volatile unsigned char __at(0x62D0) CMPCTL;




__xdata volatile unsigned char __at(0x6000) RFCORE_RAM;
__xdata volatile unsigned char __at(0x6000) RXFIFO;
__xdata volatile unsigned char __at(0x6080) TXFIFO;

__xdata volatile unsigned char __at(0x6100) SRC_ADDR_TABLE;


__xdata volatile unsigned char __at(0x6160) SRCRESMASK0;
__xdata volatile unsigned char __at(0x6161) SRCRESMASK1;
__xdata volatile unsigned char __at(0x6162) SRCRESMASK2;
__xdata volatile unsigned char __at(0x6163) SRCRESINDEX;


__xdata volatile unsigned char __at(0x6164) SRCEXTPENDEN0;
__xdata volatile unsigned char __at(0x6165) SRCEXTPENDEN1;
__xdata volatile unsigned char __at(0x6166) SRCEXTPENDEN2;
__xdata volatile unsigned char __at(0x6167) SRCSHORTPENDEN0;
__xdata volatile unsigned char __at(0x6168) SRCSHORTPENDEN1;
__xdata volatile unsigned char __at(0x6169) SRCSHORTPENDEN2;


__xdata volatile unsigned char __at(0x616A) EXT_ADDR0;
__xdata volatile unsigned char __at(0x616B) EXT_ADDR1;
__xdata volatile unsigned char __at(0x616C) EXT_ADDR2;
__xdata volatile unsigned char __at(0x616D) EXT_ADDR3;
__xdata volatile unsigned char __at(0x616E) EXT_ADDR4;
__xdata volatile unsigned char __at(0x616F) EXT_ADDR5;
__xdata volatile unsigned char __at(0x6170) EXT_ADDR6;
__xdata volatile unsigned char __at(0x6171) EXT_ADDR7;
__xdata volatile unsigned char __at(0x6172) PAN_ID0;
__xdata volatile unsigned char __at(0x6173) PAN_ID1;
__xdata volatile unsigned char __at(0x6174) SHORT_ADDR0;
__xdata volatile unsigned char __at(0x6175) SHORT_ADDR1;

__xdata volatile unsigned char __at(0x6180) FRMFILT0;
__xdata volatile unsigned char __at(0x6181) FRMFILT1;
__xdata volatile unsigned char __at(0x6182) SRCMATCH;
__xdata volatile unsigned char __at(0x6183) SRCSHORTEN0;
__xdata volatile unsigned char __at(0x6184) SRCSHORTEN1;
__xdata volatile unsigned char __at(0x6185) SRCSHORTEN2;
__xdata volatile unsigned char __at(0x6186) SRCEXTEN0;
__xdata volatile unsigned char __at(0x6187) SRCEXTEN1;
__xdata volatile unsigned char __at(0x6188) SRCEXTEN2;
__xdata volatile unsigned char __at(0x6189) FRMCTRL0;
__xdata volatile unsigned char __at(0x618A) FRMCTRL1;
__xdata volatile unsigned char __at(0x618B) RXENABLE;
__xdata volatile unsigned char __at(0x618C) RXMASKSET;
__xdata volatile unsigned char __at(0x618D) RXMASKCLR;
__xdata volatile unsigned char __at(0x618E) FREQTUNE;
__xdata volatile unsigned char __at(0x618F) FREQCTRL;
__xdata volatile unsigned char __at(0x6190) TXPOWER;
__xdata volatile unsigned char __at(0x6191) TXCTRL;
__xdata volatile unsigned char __at(0x6192) FSMSTAT0;
__xdata volatile unsigned char __at(0x6193) FSMSTAT1;
__xdata volatile unsigned char __at(0x6194) FIFOPCTRL;
__xdata volatile unsigned char __at(0x6195) FSMCTRL;
__xdata volatile unsigned char __at(0x6196) CCACTRL0;
__xdata volatile unsigned char __at(0x6197) CCACTRL1;
__xdata volatile unsigned char __at(0x6198) RSSI;
__xdata volatile unsigned char __at(0x6199) RSSISTAT;
__xdata volatile unsigned char __at(0x619A) RXFIRST;
__xdata volatile unsigned char __at(0x619B) RXFIFOCNT;
__xdata volatile unsigned char __at(0x619C) TXFIFOCNT;
__xdata volatile unsigned char __at(0x619D) RXFIRST_PTR;
__xdata volatile unsigned char __at(0x619E) RXLAST_PTR;
__xdata volatile unsigned char __at(0x619F) RXP1_PTR;
__xdata volatile unsigned char __at(0x61A1) TXFIRST_PTR;
__xdata volatile unsigned char __at(0x61A2) TXLAST_PTR;
__xdata volatile unsigned char __at(0x61A3) RFIRQM0;
__xdata volatile unsigned char __at(0x61A4) RFIRQM1;
__xdata volatile unsigned char __at(0x61A5) RFERRM;
__xdata volatile unsigned char __at(0x61A7) RFRND;
__xdata volatile unsigned char __at(0x61A8) MDMCTRL0;
__xdata volatile unsigned char __at(0x61A9) MDMCTRL1;
__xdata volatile unsigned char __at(0x61AA) FREQEST;
__xdata volatile unsigned char __at(0x61AB) RXCTRL;
__xdata volatile unsigned char __at(0x61AC) FSCTRL;
__xdata volatile unsigned char __at(0x61AD) FSCAL0;
__xdata volatile unsigned char __at(0x61AE) FSCAL1;
__xdata volatile unsigned char __at(0x61AF) FSCAL2;
__xdata volatile unsigned char __at(0x61B0) FSCAL3;
__xdata volatile unsigned char __at(0x61B1) AGCCTRL0;
__xdata volatile unsigned char __at(0x61B2) AGCCTRL1;
__xdata volatile unsigned char __at(0x61B3) AGCCTRL2;
__xdata volatile unsigned char __at(0x61B4) AGCCTRL3;
__xdata volatile unsigned char __at(0x61B5) ADCTEST0;
__xdata volatile unsigned char __at(0x61B6) ADCTEST1;
__xdata volatile unsigned char __at(0x61B7) ADCTEST2;
__xdata volatile unsigned char __at(0x61B8) MDMTEST0;
__xdata volatile unsigned char __at(0x61B9) MDMTEST1;
__xdata volatile unsigned char __at(0x61BA) DACTEST0;
__xdata volatile unsigned char __at(0x61BB) DACTEST1;
__xdata volatile unsigned char __at(0x61BC) DACTEST2;
__xdata volatile unsigned char __at(0x61BD) ATEST;
__xdata volatile unsigned char __at(0x61BE) PTEST0;
__xdata volatile unsigned char __at(0x61BF) PTEST1;
__xdata volatile unsigned char __at(0x61FA) TXFILTCFG;
__xdata volatile unsigned char __at(0x61EB) RFC_OBS_CTRL0;
__xdata volatile unsigned char __at(0x61EC) RFC_OBS_CTRL1;
__xdata volatile unsigned char __at(0x61ED) RFC_OBS_CTRL2;


__xdata volatile unsigned char __at(0x61C0) CSPPROG0;
__xdata volatile unsigned char __at(0x61C1) CSPPROG1;
__xdata volatile unsigned char __at(0x61C2) CSPPROG2;
__xdata volatile unsigned char __at(0x61C3) CSPPROG3;
__xdata volatile unsigned char __at(0x61C4) CSPPROG4;
__xdata volatile unsigned char __at(0x61C5) CSPPROG5;
__xdata volatile unsigned char __at(0x61C6) CSPPROG6;
__xdata volatile unsigned char __at(0x61C7) CSPPROG7;
__xdata volatile unsigned char __at(0x61C8) CSPPROG8;
__xdata volatile unsigned char __at(0x61C9) CSPPROG9;
__xdata volatile unsigned char __at(0x61CA) CSPPROG10;
__xdata volatile unsigned char __at(0x61CB) CSPPROG11;
__xdata volatile unsigned char __at(0x61CC) CSPPROG12;
__xdata volatile unsigned char __at(0x61CD) CSPPROG13;
__xdata volatile unsigned char __at(0x61CE) CSPPROG14;
__xdata volatile unsigned char __at(0x61CF) CSPPROG15;
__xdata volatile unsigned char __at(0x61D0) CSPPROG16;
__xdata volatile unsigned char __at(0x61D1) CSPPROG17;
__xdata volatile unsigned char __at(0x61D2) CSPPROG18;
__xdata volatile unsigned char __at(0x61D3) CSPPROG19;
__xdata volatile unsigned char __at(0x61D4) CSPPROG20;
__xdata volatile unsigned char __at(0x61D5) CSPPROG21;
__xdata volatile unsigned char __at(0x61D6) CSPPROG22;
__xdata volatile unsigned char __at(0x61D7) CSPPROG23;
__xdata volatile unsigned char __at(0x61E0) CSPCTRL;
__xdata volatile unsigned char __at(0x61E1) CSPSTAT;
__xdata volatile unsigned char __at(0x61E2) CSPX;
__xdata volatile unsigned char __at(0x61E3) CSPY;
__xdata volatile unsigned char __at(0x61E4) CSPZ;
__xdata volatile unsigned char __at(0x61E5) CSPT;




__xdata volatile unsigned char __at(0x6200) USBADDR;
__xdata volatile unsigned char __at(0x6201) USBPOW;
__xdata volatile unsigned char __at(0x6202) USBIIF;
__xdata volatile unsigned char __at(0x6204) USBOIF;
__xdata volatile unsigned char __at(0x6206) USBCIF;
__xdata volatile unsigned char __at(0x6207) USBIIE;
__xdata volatile unsigned char __at(0x6209) USBOIE;
__xdata volatile unsigned char __at(0x620B) USBCIE;
__xdata volatile unsigned char __at(0x620C) USBFRML;
__xdata volatile unsigned char __at(0x620D) USBFRMH;
__xdata volatile unsigned char __at(0x620E) USBINDEX;
__xdata volatile unsigned char __at(0x620F) USBCTRL;
__xdata volatile unsigned char __at(0x6210) USBMAXI;
__xdata volatile unsigned char __at(0x6211) USBCS0;
__xdata volatile unsigned char __at(0x6211) USBCSIL;
__xdata volatile unsigned char __at(0x6212) USBCSIH;
__xdata volatile unsigned char __at(0x6213) USBMAXO;
__xdata volatile unsigned char __at(0x6214) USBCSOL;
__xdata volatile unsigned char __at(0x6215) USBCSOH;
__xdata volatile unsigned char __at(0x6216) USBCNT0;
__xdata volatile unsigned char __at(0x6216) USBCNTL;
__xdata volatile unsigned char __at(0x6217) USBCNTH;
__xdata volatile unsigned char __at(0x6220) USBF0;
__xdata volatile unsigned char __at(0x6222) USBF1;
__xdata volatile unsigned char __at(0x6224) USBF2;
__xdata volatile unsigned char __at(0x6226) USBF3;
__xdata volatile unsigned char __at(0x6228) USBF4;
__xdata volatile unsigned char __at(0x622A) USBF5;



__xdata volatile unsigned char __at(0x7080) X_P0;
__xdata volatile unsigned char __at(0x7086) X_U0CSR;
__xdata volatile unsigned char __at(0x7089) X_P0IFG;
__xdata volatile unsigned char __at(0x708A) X_P1IFG;
__xdata volatile unsigned char __at(0x708B) X_P2IFG;
__xdata volatile unsigned char __at(0x708C) X_PICTL;
__xdata volatile unsigned char __at(0x708D) X_P1IEN;
__xdata volatile unsigned char __at(0x708F) X_P0INP;
__xdata volatile unsigned char __at(0x7090) X_P1;
__xdata volatile unsigned char __at(0x7091) X_RFIRQF1;
__xdata volatile unsigned char __at(0x7093) X_MPAGE;
__xdata volatile unsigned char __at(0x7093) X__XPAGE;
__xdata volatile unsigned char __at(0x7094) X_T2CTRL;
__xdata volatile unsigned char __at(0x7095) X_ST0;
__xdata volatile unsigned char __at(0x7096) X_ST1;
__xdata volatile unsigned char __at(0x7097) X_ST2;
__xdata volatile unsigned char __at(0x709C) X_T2EVTCFG;
__xdata volatile unsigned char __at(0x709D) X_SLEEPSTA;
__xdata volatile unsigned char __at(0x709E) X_CLKCONSTA;
__xdata volatile unsigned char __at(0x709F) X_FMAP;
__xdata volatile unsigned char __at(0x709F) X_PSBANK;
__xdata volatile unsigned char __at(0x70A0) X_P2;
__xdata volatile unsigned char __at(0x70A1) X_T2IRQF;
__xdata volatile unsigned char __at(0x70A2) X_T2M0;
__xdata volatile unsigned char __at(0x70A3) X_T2M1;
__xdata volatile unsigned char __at(0x70A4) X_T2MOVF0;
__xdata volatile unsigned char __at(0x70A5) X_T2MOVF1;
__xdata volatile unsigned char __at(0x70A6) X_T2MOVF2;
__xdata volatile unsigned char __at(0x70A7) X_T2IRQM;
__xdata volatile unsigned char __at(0x70AB) X_P0IEN;
__xdata volatile unsigned char __at(0x70AC) X_P2IEN;
__xdata volatile unsigned char __at(0x70AD) X_STLOAD;
__xdata volatile unsigned char __at(0x70AE) X_PMUX;
__xdata volatile unsigned char __at(0x70AF) X_T1STAT;
__xdata volatile unsigned char __at(0x70B1) X_ENCDI;
__xdata volatile unsigned char __at(0x70B2) X_ENCDO;
__xdata volatile unsigned char __at(0x70B3) X_ENCCS;
__xdata volatile unsigned char __at(0x70B4) X_ADCCON1;
__xdata volatile unsigned char __at(0x70B5) X_ADCCON2;
__xdata volatile unsigned char __at(0x70B6) X_ADCCON3;
__xdata volatile unsigned char __at(0x70BA) X_ADCL;
__xdata volatile unsigned char __at(0x70BB) X_ADCH;
__xdata volatile unsigned char __at(0x70BC) X_RNDL;
__xdata volatile unsigned char __at(0x70BD) X_RNDH;
__xdata volatile unsigned char __at(0x70BE) X_SLEEPCMD;
__xdata volatile unsigned char __at(0x70BF) X_RFERRF;
__xdata volatile unsigned char __at(0x70C1) X_U0DBUF;
__xdata volatile unsigned char __at(0x70C2) X_U0BAUD;
__xdata volatile unsigned char __at(0x70C3) X_T2MSEL;
__xdata volatile unsigned char __at(0x70C4) X_U0UCR;
__xdata volatile unsigned char __at(0x70C5) X_U0GCR;
__xdata volatile unsigned char __at(0x70C6) X_CLKCONCMD;
__xdata volatile unsigned char __at(0x70C7) X_MEMCTR;
__xdata volatile unsigned char __at(0x70C9) X_WDCTL;
__xdata volatile unsigned char __at(0x70CA) X_T3CNT;
__xdata volatile unsigned char __at(0x70CB) X_T3CTL;
__xdata volatile unsigned char __at(0x70CC) X_T3CCTL0;
__xdata volatile unsigned char __at(0x70CD) X_T3CC0;
__xdata volatile unsigned char __at(0x70CE) X_T3CCTL1;
__xdata volatile unsigned char __at(0x70CF) X_T3CC1;
__xdata volatile unsigned char __at(0x70D1) X_DMAIRQ;
__xdata volatile unsigned char __at(0x70D2) X_DMA1CFGL;
__xdata volatile unsigned char __at(0x70D3) X_DMA1CFGH;
__xdata volatile unsigned char __at(0x70D4) X_DMA0CFGL;
__xdata volatile unsigned char __at(0x70D5) X_DMA0CFGH;
__xdata volatile unsigned char __at(0x70D6) X_DMAARM;
__xdata volatile unsigned char __at(0x70D7) X_DMAREQ;
__xdata volatile unsigned char __at(0x70D8) X_TIMIF;
__xdata volatile unsigned char __at(0x70D9) X_RFD;
__xdata volatile unsigned char __at(0x70DA) X_T1CC0L;
__xdata volatile unsigned char __at(0x70DB) X_T1CC0H;
__xdata volatile unsigned char __at(0x70DC) X_T1CC1L;
__xdata volatile unsigned char __at(0x70DD) X_T1CC1H;
__xdata volatile unsigned char __at(0x70DE) X_T1CC2L;
__xdata volatile unsigned char __at(0x70DF) X_T1CC2H;
__xdata volatile unsigned char __at(0x70E1) X_RFST;
__xdata volatile unsigned char __at(0x70E2) X_T1CNTL;
__xdata volatile unsigned char __at(0x70E3) X_T1CNTH;
__xdata volatile unsigned char __at(0x70E4) X_T1CTL;
__xdata volatile unsigned char __at(0x70E5) X_T1CCTL0;
__xdata volatile unsigned char __at(0x70E6) X_T1CCTL1;
__xdata volatile unsigned char __at(0x70E7) X_T1CCTL2;
__xdata volatile unsigned char __at(0x70E9) X_RFIRQF0;
__xdata volatile unsigned char __at(0x70EA) X_T4CNT;
__xdata volatile unsigned char __at(0x70EB) X_T4CTL;
__xdata volatile unsigned char __at(0x70EC) X_T4CCTL0;
__xdata volatile unsigned char __at(0x70ED) X_T4CC0;
__xdata volatile unsigned char __at(0x70EE) X_T4CCTL1;
__xdata volatile unsigned char __at(0x70EF) X_T4CC1;
__xdata volatile unsigned char __at(0x70F1) X_PERCFG;
__xdata volatile unsigned char __at(0x70F2) X_APCFG;
__xdata volatile unsigned char __at(0x70F3) X_P0SEL;
__xdata volatile unsigned char __at(0x70F4) X_P1SEL;
__xdata volatile unsigned char __at(0x70F5) X_P2SEL;
__xdata volatile unsigned char __at(0x70F6) X_P1INP;
__xdata volatile unsigned char __at(0x70F7) X_P2INP;
__xdata volatile unsigned char __at(0x70F8) X_U1CSR;
__xdata volatile unsigned char __at(0x70F9) X_U1DBUF;
__xdata volatile unsigned char __at(0x70FA) X_U1BAUD;
__xdata volatile unsigned char __at(0x70FB) X_U1UCR;
__xdata volatile unsigned char __at(0x70FC) X_U1GCR;
__xdata volatile unsigned char __at(0x70FD) X_P0DIR;
__xdata volatile unsigned char __at(0x70FE) X_P1DIR;
__xdata volatile unsigned char __at(0x70FF) X_P2DIR;



__xdata volatile unsigned char __at(0x7800) X_INFOPAGE;
__xdata volatile unsigned char __at(0x780C) X_IEEE_ADDR;
# 49 "../../../cpu/cc253x/./rtimer-arch.h" 2
# 58 "../../../cpu/cc253x/./rtimer-arch.h"
void rtimer_isr(void) __interrupt(9);
# 63 "../../../core/./sys/rtimer.h" 2
# 71 "../../../core/./sys/rtimer.h"
void rtimer_init(void);

struct rtimer;
typedef void (* rtimer_callback_t)(struct rtimer *t, void *ptr);
# 83 "../../../core/./sys/rtimer.h"
struct rtimer {
  rtimer_clock_t time;
  rtimer_callback_t func;
  void *ptr;
};

enum {
  RTIMER_OK,
  RTIMER_ERR_FULL,
  RTIMER_ERR_TIME,
  RTIMER_ERR_ALREADY_SCHEDULED,
};
# 110 "../../../core/./sys/rtimer.h"
int rtimer_set(struct rtimer *task, rtimer_clock_t time,
        rtimer_clock_t duration, rtimer_callback_t func, void *ptr);
# 120 "../../../core/./sys/rtimer.h"
void rtimer_run_next(void);
# 147 "../../../core/./sys/rtimer.h"
void rtimer_arch_init(void);
void rtimer_arch_schedule(rtimer_clock_t t);
# 47 "../../../core/./contiki.h" 2

# 1 "../../../core/./sys/pt.h" 1
# 49 "../../../core/./contiki.h" 2

# 1 "../../../core/./sys/procinit.h" 1
# 42 "../../../core/./sys/procinit.h"
void procinit_init(void);
# 51 "../../../core/./contiki.h" 2

# 1 "../../../core/./sys/loader.h" 1
# 53 "../../../core/./contiki.h" 2
# 1 "../../../core/./sys/clock.h" 1
# 54 "../../../core/./contiki.h" 2

# 1 "../../../core/./sys/energest.h" 1
# 43 "../../../core/./sys/energest.h"
# 1 "../../../core/./sys/rtimer.h" 1
# 44 "../../../core/./sys/energest.h" 2

typedef struct {

  unsigned long current;
} energest_t;

enum energest_type {
  ENERGEST_TYPE_CPU,
  ENERGEST_TYPE_LPM,
  ENERGEST_TYPE_IRQ,
  ENERGEST_TYPE_LED_GREEN,
  ENERGEST_TYPE_LED_YELLOW,
  ENERGEST_TYPE_LED_RED,
  ENERGEST_TYPE_TRANSMIT,
  ENERGEST_TYPE_LISTEN,

  ENERGEST_TYPE_FLASH_READ,
  ENERGEST_TYPE_FLASH_WRITE,

  ENERGEST_TYPE_SENSORS,

  ENERGEST_TYPE_SERIAL,

  ENERGEST_TYPE_MAX
};

void energest_init(void);
unsigned long energest_type_time(int type);



void energest_type_set(int type, unsigned long value);
void energest_flush(void);
# 56 "../../../core/./contiki.h" 2
# 90 "../../../core/./net/psock.h" 2
# 1 "../../../core/./contiki-lib.h" 1
# 37 "../../../core/./contiki-lib.h"
# 1 "../../../core/./contiki.h" 1
# 38 "../../../core/./contiki-lib.h" 2
# 1 "../../../core/./lib/list.h" 1
# 135 "../../../core/./lib/list.h"
typedef void ** list_t;

void list_init(list_t list);
void * list_head(list_t list);
void * list_tail(list_t list);
void * list_pop (list_t list);
void list_push(list_t list, void *item);

void * list_chop(list_t list);

void list_add(list_t list, void *item);
void list_remove(list_t list, void *item);

int list_length(list_t list);

void list_copy(list_t dest, list_t src);

void list_insert(list_t list, void *previtem, void *newitem);

void * list_item_next(void *item);
# 39 "../../../core/./contiki-lib.h" 2
# 1 "../../../core/./lib/memb.h" 1
# 96 "../../../core/./lib/memb.h"
struct memb {
  unsigned short size;
  unsigned short num;
  char *count;
  void *mem;
};






void memb_init(struct memb *m);






void *memb_alloc(struct memb *m);
# 129 "../../../core/./lib/memb.h"
char memb_free(struct memb *m, void *ptr);

int memb_inmemb(struct memb *m, void *ptr);
# 40 "../../../core/./contiki-lib.h" 2
# 1 "../../../core/./lib/mmem.h" 1
# 77 "../../../core/./lib/mmem.h"
struct mmem {
  struct mmem *next;
  unsigned int size;
  void *ptr;
};




int mmem_alloc(struct mmem *m, unsigned int size);
void mmem_free(struct mmem *);
void mmem_init(void);
# 41 "../../../core/./contiki-lib.h" 2
# 1 "../../../core/./lib/random.h" 1
# 39 "../../../core/./lib/random.h"
void random_init(unsigned short seed);






unsigned short random_rand(void);
# 42 "../../../core/./contiki-lib.h" 2
# 91 "../../../core/./net/psock.h" 2
# 1 "../../../core/./contiki-net.h" 1
# 39 "../../../core/./contiki-net.h"
# 1 "../../../core/./net/tcpip.h" 1
# 71 "../../../core/./net/tcpip.h"
struct uip_conn;

struct tcpip_uipstate {
  struct process *p;
  void *state;
};







typedef struct tcpip_uipstate uip_udp_appstate_t;
typedef struct tcpip_uipstate uip_tcp_appstate_t;
typedef struct tcpip_uipstate uip_icmp6_appstate_t;
# 1 "../../../core/./net/uip.h" 1
# 56 "../../../core/./net/uip.h"
# 1 "../../../core/./net/uipopt.h" 1
# 571 "../../../core/./net/uipopt.h"
void uip_log(char *msg);
# 57 "../../../core/./net/uip.h" 2





typedef union uip_ip4addr_t {
  uint8_t u8[4];
  uint16_t u16[2];
} uip_ip4addr_t;

typedef union uip_ip6addr_t {
  uint8_t u8[16];
  uint16_t u16[8];
} uip_ip6addr_t;


typedef uip_ip6addr_t uip_ipaddr_t;
# 82 "../../../core/./net/uip.h"
typedef struct uip_802154_shortaddr {
  uint8_t addr[2];
} uip_802154_shortaddr;

typedef struct uip_802154_longaddr {
  uint8_t addr[8];
} uip_802154_longaddr;


typedef struct uip_80211_addr {
  uint8_t addr[6];
} uip_80211_addr;


typedef struct uip_eth_addr {
  uint8_t addr[6];
} uip_eth_addr;




typedef uip_802154_longaddr uip_lladdr_t;
# 119 "../../../core/./net/uip.h"
# 1 "../../../core/./net/tcpip.h" 1
# 120 "../../../core/./net/uip.h" 2
# 238 "../../../core/./net/uip.h"
void uip_init(void);






void uip_setipid(uint16_t id);
# 448 "../../../core/./net/uip.h"
void uip_reass_over(void);
# 477 "../../../core/./net/uip.h"
typedef union {
  uint32_t u32[((240) + 3) / 4];
  uint8_t u8[(240)];
} uip_buf_t;

 extern uip_buf_t uip_aligned_buf;
# 512 "../../../core/./net/uip.h"
void uip_listen(uint16_t port);
# 526 "../../../core/./net/uip.h"
void uip_unlisten(uint16_t port);
# 560 "../../../core/./net/uip.h"
struct uip_conn *uip_connect(uip_ipaddr_t *ripaddr, uint16_t port);
# 600 "../../../core/./net/uip.h"
 void uip_send(const void *data, int len);
# 828 "../../../core/./net/uip.h"
struct uip_udp_conn *uip_udp_new(const uip_ipaddr_t *ripaddr, uint16_t rport);
# 1217 "../../../core/./net/uip.h"
 uint16_t uip_htons(uint16_t val);






 uint32_t uip_htonl(uint32_t val);
# 1239 "../../../core/./net/uip.h"
 extern void *uip_appdata;
# 1274 "../../../core/./net/uip.h"
 extern uint16_t uip_len;




extern uint8_t uip_ext_len;
# 1297 "../../../core/./net/uip.h"
struct uip_conn {
  uip_ipaddr_t ripaddr;

  uint16_t lport;
  uint16_t rport;


  uint8_t rcv_nxt[4];

  uint8_t snd_nxt[4];

  uint16_t len;
  uint16_t mss;

  uint16_t initialmss;

  uint8_t sa;

  uint8_t sv;

  uint8_t rto;
  uint8_t tcpstateflags;
  uint8_t timer;
  uint8_t nrtx;



  uip_tcp_appstate_t appstate;
};
# 1335 "../../../core/./net/uip.h"
 extern struct uip_conn *uip_conn;


 extern struct uip_conn uip_conns[10];
# 1349 "../../../core/./net/uip.h"
extern uint8_t uip_acc32[4];





struct uip_udp_conn {
  uip_ipaddr_t ripaddr;
  uint16_t lport;
  uint16_t rport;
  uint8_t ttl;


  uip_udp_appstate_t appstate;
};




extern struct uip_udp_conn *uip_udp_conn;
extern struct uip_udp_conn uip_udp_conns[10];

struct uip_fallback_interface {
  void (*init)(void);
  void (*output)(void);
};
# 1400 "../../../core/./net/uip.h"
struct uip_stats {
  struct {
    uip_stats_t recv;

    uip_stats_t sent;

    uip_stats_t forwarded;

    uip_stats_t drop;

    uip_stats_t vhlerr;

    uip_stats_t hblenerr;

    uip_stats_t lblenerr;

    uip_stats_t fragerr;

    uip_stats_t chkerr;

    uip_stats_t protoerr;

  } ip;
  struct {
    uip_stats_t recv;
    uip_stats_t sent;
    uip_stats_t drop;
    uip_stats_t typeerr;

    uip_stats_t chkerr;

  } icmp;

  struct {
    uip_stats_t recv;
    uip_stats_t sent;
    uip_stats_t drop;
    uip_stats_t chkerr;

    uip_stats_t ackerr;

    uip_stats_t rst;
    uip_stats_t rexmit;
    uip_stats_t syndrop;

    uip_stats_t synrst;

  } tcp;


  struct {
    uip_stats_t drop;
    uip_stats_t recv;
    uip_stats_t sent;
    uip_stats_t chkerr;

  } udp;


  struct {
    uip_stats_t drop;
    uip_stats_t recv;
    uip_stats_t sent;
  } nd6;

};
# 1482 "../../../core/./net/uip.h"
 extern uint8_t uip_flags;
# 1534 "../../../core/./net/uip.h"
void uip_process(uint8_t flag);
# 1573 "../../../core/./net/uip.h"
struct uip_tcpip_hdr {


  uint8_t vtc,
    tcflow;
  uint16_t flow;
  uint8_t len[2];
  uint8_t proto, ttl;
  uip_ip6addr_t srcipaddr, destipaddr;
# 1596 "../../../core/./net/uip.h"
  uint16_t srcport,
    destport;
  uint8_t seqno[4],
    ackno[4],
    tcpoffset,
    flags,
    wnd[2];
  uint16_t tcpchksum;
  uint8_t urgp[2];
  uint8_t optdata[4];
};


struct uip_icmpip_hdr {


  uint8_t vtc,
    tcf;
  uint16_t flow;
  uint8_t len[2];
  uint8_t proto, ttl;
  uip_ip6addr_t srcipaddr, destipaddr;
# 1632 "../../../core/./net/uip.h"
  uint8_t type, icode;
  uint16_t icmpchksum;




};



struct uip_udpip_hdr {


  uint8_t vtc,
    tcf;
  uint16_t flow;
  uint8_t len[2];
  uint8_t proto, ttl;
  uip_ip6addr_t srcipaddr, destipaddr;
# 1665 "../../../core/./net/uip.h"
  uint16_t srcport,
    destport;
  uint16_t udplen;
  uint16_t udpchksum;
};







struct uip_ip_hdr {


  uint8_t vtc;
  uint8_t tcflow;
  uint16_t flow;
  uint8_t len[2];
  uint8_t proto, ttl;
  uip_ip6addr_t srcipaddr, destipaddr;
# 1698 "../../../core/./net/uip.h"
};
# 1722 "../../../core/./net/uip.h"
typedef struct uip_ext_hdr {
  uint8_t next;
  uint8_t len;
} uip_ext_hdr;


typedef struct uip_hbho_hdr {
  uint8_t next;
  uint8_t len;
} uip_hbho_hdr;


typedef struct uip_desto_hdr {
  uint8_t next;
  uint8_t len;
} uip_desto_hdr;
# 1749 "../../../core/./net/uip.h"
typedef struct uip_routing_hdr {
  uint8_t next;
  uint8_t len;
  uint8_t routing_type;
  uint8_t seg_left;
} uip_routing_hdr;


typedef struct uip_frag_hdr {
  uint8_t next;
  uint8_t res;
  uint16_t offsetresmore;
  uint32_t id;
} uip_frag_hdr;





typedef struct uip_ext_hdr_opt {
  uint8_t type;
  uint8_t len;
} uip_ext_hdr_opt;


typedef struct uip_ext_hdr_opt_padn {
  uint8_t opt_type;
  uint8_t opt_len;
} uip_ext_hdr_opt_padn;


typedef struct uip_ext_hdr_opt_rpl {
  uint8_t opt_type;
  uint8_t opt_len;
  uint8_t flags;
  uint8_t instance;
  uint16_t senderrank;
} uip_ext_hdr_opt_rpl;


struct uip_tcp_hdr {
  uint16_t srcport;
  uint16_t destport;
  uint8_t seqno[4];
  uint8_t ackno[4];
  uint8_t tcpoffset;
  uint8_t flags;
  uint8_t wnd[2];
  uint16_t tcpchksum;
  uint8_t urgp[2];
  uint8_t optdata[4];
};


struct uip_icmp_hdr {
  uint8_t type, icode;
  uint16_t icmpchksum;



};



struct uip_udp_hdr {
  uint16_t srcport;
  uint16_t destport;
  uint16_t udplen;
  uint16_t udpchksum;
};
# 1925 "../../../core/./net/uip.h"
 extern uip_ipaddr_t uip_hostaddr, uip_netmask, uip_draddr;

 extern const uip_ipaddr_t uip_broadcast_addr;
 extern const uip_ipaddr_t uip_all_zeroes_addr;




 extern uip_lladdr_t uip_lladdr;
# 2153 "../../../core/./net/uip.h"
uint16_t uip_chksum(uint16_t *buf, uint16_t len);
# 2164 "../../../core/./net/uip.h"
uint16_t uip_ipchksum(void);
# 2175 "../../../core/./net/uip.h"
uint16_t uip_tcpchksum(void);
# 2186 "../../../core/./net/uip.h"
uint16_t uip_udpchksum(void);






uint16_t uip_icmp6chksum(void);
# 88 "../../../core/./net/tcpip.h" 2
void tcpip_uipcall(void);
# 110 "../../../core/./net/tcpip.h"
 void tcp_attach(struct uip_conn *conn,
       void *appstate);
# 128 "../../../core/./net/tcpip.h"
 void tcp_listen(uint16_t port);
# 142 "../../../core/./net/tcpip.h"
 void tcp_unlisten(uint16_t port);
# 167 "../../../core/./net/tcpip.h"
 struct uip_conn *tcp_connect(uip_ipaddr_t *ripaddr, uint16_t port,
      void *appstate);
# 181 "../../../core/./net/tcpip.h"
void tcpip_poll_tcp(struct uip_conn *conn);
# 190 "../../../core/./net/tcpip.h"
struct uip_udp_conn;
# 206 "../../../core/./net/tcpip.h"
void udp_attach(struct uip_udp_conn *conn,
  void *appstate);
# 228 "../../../core/./net/tcpip.h"
 struct uip_udp_conn *udp_new(const uip_ipaddr_t *ripaddr, uint16_t port,
      void *appstate);
# 243 "../../../core/./net/tcpip.h"
struct uip_udp_conn *udp_broadcast_new(uint16_t port, void *appstate);
# 274 "../../../core/./net/tcpip.h"
 void tcpip_poll_udp(struct uip_udp_conn *conn);
# 320 "../../../core/./net/tcpip.h"
 extern process_event_t tcpip_event;
# 336 "../../../core/./net/tcpip.h"
 void tcpip_input(void);






uint8_t tcpip_output(uip_lladdr_t *);
void tcpip_set_outputfunc(uint8_t (* f)(uip_lladdr_t *));
# 354 "../../../core/./net/tcpip.h"
void tcpip_ipv6_output(void);





extern unsigned char tcpip_do_forwarding;




extern unsigned char tcpip_is_forwarding;






extern struct process tcpip_process;
# 40 "../../../core/./contiki-net.h" 2
# 1 "../../../core/./net/uip.h" 1
# 41 "../../../core/./contiki-net.h" 2
# 1 "../../../core/./net/uip-fw.h" 1
# 53 "../../../core/./net/uip-fw.h"
struct uip_fw_netif {
  struct uip_fw_netif *next;

  uip_ipaddr_t ipaddr;
  uip_ipaddr_t netmask;
  uint8_t (* output)(void);


};
# 110 "../../../core/./net/uip-fw.h"
void uip_fw_init(void);
uint8_t uip_fw_forward(void);
uint8_t uip_fw_output(void);
void uip_fw_register(struct uip_fw_netif *netif);
void uip_fw_default(struct uip_fw_netif *netif);
void uip_fw_periodic(void);
# 42 "../../../core/./contiki-net.h" 2
# 1 "../../../core/./net/uip-fw-drv.h" 1
# 38 "../../../core/./net/uip-fw-drv.h"
# 1 "../../../core/./net/uip-fw.h" 1
# 39 "../../../core/./net/uip-fw-drv.h" 2

extern struct process uip_fw_process;
# 43 "../../../core/./contiki-net.h" 2
# 1 "../../../core/./net/uip_arp.h" 1
# 57 "../../../core/./net/uip_arp.h"
 extern struct uip_eth_addr uip_ethaddr;




struct uip_eth_hdr {
  struct uip_eth_addr dest;
  struct uip_eth_addr src;
  uint16_t type;
};
# 75 "../../../core/./net/uip_arp.h"
void uip_arp_init(void);
# 91 "../../../core/./net/uip_arp.h"
void uip_arp_arpin(void);
# 103 "../../../core/./net/uip_arp.h"
void uip_arp_out(void);



void uip_arp_timer(void);
# 44 "../../../core/./contiki-net.h" 2
# 1 "../../../core/./net/uiplib.h" 1
# 69 "../../../core/./net/uiplib.h"
 int uiplib_ipaddrconv(const char *addrstr, uip_ipaddr_t *addr);

 int uiplib_ip4addrconv(const char *addrstr, uip_ip4addr_t *addr);
 int uiplib_ip6addrconv(const char *addrstr, uip_ip6addr_t *addr);
# 45 "../../../core/./contiki-net.h" 2
# 1 "../../../core/./net/uip-udp-packet.h" 1
# 45 "../../../core/./net/uip-udp-packet.h"
void uip_udp_packet_send(struct uip_udp_conn *c, const void *data, int len);
void uip_udp_packet_sendto(struct uip_udp_conn *c, const void *data, int len,
      const uip_ipaddr_t *toaddr, uint16_t toport);
# 46 "../../../core/./contiki-net.h" 2
# 1 "../../../core/./net/simple-udp.h" 1
# 58 "../../../core/./net/simple-udp.h"
struct simple_udp_connection;

typedef void (* simple_udp_callback)(struct simple_udp_connection *c,
                                     const uip_ipaddr_t *source_addr,
                                     uint16_t source_port,
                                     const uip_ipaddr_t *dest_addr,
                                     uint16_t dest_port,
                                     const uint8_t *data, uint16_t datalen);

struct simple_udp_connection {
  struct simple_udp_connection *next;
  uip_ipaddr_t remote_addr;
  uint16_t remote_port, local_port;
  simple_udp_callback receive_callback;
  struct uip_udp_conn *udp_conn;
  struct process *client_process;
};

int simple_udp_register(struct simple_udp_connection *c,
                        uint16_t local_port,
                        uip_ipaddr_t *remote_addr,
                        uint16_t remote_port,
                        simple_udp_callback receive_callback);

int simple_udp_send(struct simple_udp_connection *c,
                    const void *data, uint16_t datalen);

int simple_udp_sendto(struct simple_udp_connection *c,
                      const void *data, uint16_t datalen,
                      const uip_ipaddr_t *to);

int simple_udp_sendto_port(struct simple_udp_connection *c,
      const void *data, uint16_t datalen,
      const uip_ipaddr_t *to, uint16_t to_port);

void simple_udp_init(void);
# 47 "../../../core/./contiki-net.h" 2


# 1 "../../../core/./net/uip-icmp6.h" 1
# 101 "../../../core/./net/uip-icmp6.h"
typedef struct uip_icmp6_error{
  uint32_t param;
} uip_icmp6_error;
# 113 "../../../core/./net/uip-icmp6.h"
void
uip_icmp6_echo_request_input(void);







void
uip_icmp6_error_output(uint8_t type, uint8_t code, uint32_t param);
# 132 "../../../core/./net/uip-icmp6.h"
void
uip_icmp6_send(uip_ipaddr_t *dest, uint8_t type, uint8_t code, uint8_t payload_len);
# 50 "../../../core/./contiki-net.h" 2
# 1 "../../../core/./net/uip-ds6.h" 1
# 46 "../../../core/./net/uip-ds6.h"
# 1 "../../../core/./sys/stimer.h" 1
# 81 "../../../core/./sys/stimer.h"
struct stimer {
  unsigned long start;
  unsigned long interval;
};

void stimer_set(struct stimer *t, unsigned long interval);
void stimer_reset(struct stimer *t);
void stimer_restart(struct stimer *t);
int stimer_expired(struct stimer *t);
unsigned long stimer_remaining(struct stimer *t);
unsigned long stimer_elapsed(struct stimer *t);
# 47 "../../../core/./net/uip-ds6.h" 2

# 1 "../../../core/./net/uip-nd6.h" 1
# 196 "../../../core/./net/uip-nd6.h"
typedef struct uip_nd6_ns {
  uint32_t reserved;
  uip_ipaddr_t tgtipaddr;
} uip_nd6_ns;






typedef struct uip_nd6_na {
  uint8_t flagsreserved;
  uint8_t reserved[3];
  uip_ipaddr_t tgtipaddr;
} uip_nd6_na;






typedef struct uip_nd6_rs {
  uint32_t reserved;
} uip_nd6_rs;






typedef struct uip_nd6_ra {
  uint8_t cur_ttl;
  uint8_t flags_reserved;
  uint16_t router_lifetime;
  uint32_t reachable_time;
  uint32_t retrans_timer;
} uip_nd6_ra;






typedef struct uip_nd6_redirect {
  uint32_t reserved;
  uip_ipaddr_t tgtipaddress;
  uip_ipaddr_t destipaddress;
} uip_nd6_redirect;
# 252 "../../../core/./net/uip-nd6.h"
typedef struct uip_nd6_opt_hdr {
  uint8_t type;
  uint8_t len;
} uip_nd6_opt_hdr;


typedef struct uip_nd6_opt_prefix_info {
  uint8_t type;
  uint8_t len;
  uint8_t preflen;
  uint8_t flagsreserved1;
  uint32_t validlt;
  uint32_t preferredlt;
  uint32_t reserved2;
  uip_ipaddr_t prefix;
} uip_nd6_opt_prefix_info ;


typedef struct uip_nd6_opt_mtu {
  uint8_t type;
  uint8_t len;
  uint16_t reserved;
  uint32_t mtu;
} uip_nd6_opt_mtu;


typedef struct uip_nd6_opt_redirected_hdr {
  uint8_t type;
  uint8_t len;
  uint8_t reserved[6];
} uip_nd6_opt_redirected_hdr;
# 310 "../../../core/./net/uip-nd6.h"
void
uip_nd6_ns_input(void);
# 333 "../../../core/./net/uip-nd6.h"
void
uip_nd6_ns_output(uip_ipaddr_t *src, uip_ipaddr_t *dest, uip_ipaddr_t *tgt);
# 353 "../../../core/./net/uip-nd6.h"
void
uip_nd6_na_input(void);
# 384 "../../../core/./net/uip-nd6.h"
void uip_nd6_rs_output(void);
# 396 "../../../core/./net/uip-nd6.h"
void
uip_nd6_ra_input(void);



void
uip_appserver_addr_get(uip_ipaddr_t *ipaddr);
# 49 "../../../core/./net/uip-ds6.h" 2
# 1 "../../../core/./net/uip-ds6-route.h" 1
# 35 "../../../core/./net/uip-ds6-route.h"
void uip_ds6_route_init(void);
# 47 "../../../core/./net/uip-ds6-route.h"
typedef void (* uip_ds6_notification_callback)(int event,
            uip_ipaddr_t *route,
            uip_ipaddr_t *nexthop,
            int num_routes);
struct uip_ds6_notification {
  struct uip_ds6_notification *next;
  uip_ds6_notification_callback callback;
};

void uip_ds6_notification_add(struct uip_ds6_notification *n,
         uip_ds6_notification_callback c);
# 75 "../../../core/./net/uip-ds6-route.h"
typedef struct rpl_route_entry {
  uint32_t lifetime;
  uint32_t saved_lifetime;
  void *dag;
  uint8_t learned_from;
} rpl_route_entry_t;





typedef struct uip_ds6_route {
  struct uip_ds6_route *next;
  uip_ipaddr_t ipaddr;
  uip_ipaddr_t nexthop;
  uint8_t length;
  uint8_t metric;

  rpl_route_entry_t state;

} uip_ds6_route_t;




typedef struct uip_ds6_defrt {
  struct uip_ds6_defrt *next;
  uip_ipaddr_t ipaddr;
  struct stimer lifetime;
  uint8_t isinfinite;
} uip_ds6_defrt_t;



uip_ds6_defrt_t *uip_ds6_defrt_add(uip_ipaddr_t *ipaddr,
                                   unsigned long interval);
void uip_ds6_defrt_rm(uip_ds6_defrt_t *defrt);
uip_ds6_defrt_t *uip_ds6_defrt_lookup(uip_ipaddr_t *ipaddr);
uip_ipaddr_t *uip_ds6_defrt_choose(void);

void uip_ds6_defrt_periodic(void);





uip_ds6_route_t *uip_ds6_route_lookup(uip_ipaddr_t *destipaddr);
uip_ds6_route_t *uip_ds6_route_add(uip_ipaddr_t *ipaddr, uint8_t length,
                                   uip_ipaddr_t *next_hop, uint8_t metric);
void uip_ds6_route_rm(uip_ds6_route_t *route);
void uip_ds6_route_rm_by_nexthop(uip_ipaddr_t *nexthop);

int uip_ds6_route_num_routes(void);
uip_ds6_route_t *uip_ds6_route_list_head(void);
# 50 "../../../core/./net/uip-ds6.h" 2
# 159 "../../../core/./net/uip-ds6.h"
typedef struct uip_ds6_nbr {
  uint8_t isused;
  uip_ipaddr_t ipaddr;
  uip_lladdr_t lladdr;
  struct stimer reachable;
  struct stimer sendns;
  clock_time_t last_lookup;
  uint8_t nscount;
  uint8_t isrouter;
  uint8_t state;




} uip_ds6_nbr_t;



typedef struct uip_ds6_prefix {
  uint8_t isused;
  uip_ipaddr_t ipaddr;
  uint8_t length;
  uint8_t advertise;
  uint32_t vlifetime;
  uint32_t plifetime;
  uint8_t l_a_reserved;
} uip_ds6_prefix_t;
# 197 "../../../core/./net/uip-ds6.h"
typedef struct uip_ds6_addr {
  uint8_t isused;
  uip_ipaddr_t ipaddr;
  uint8_t state;
  uint8_t type;
  uint8_t isinfinite;
  struct stimer vlifetime;




} uip_ds6_addr_t;


typedef struct uip_ds6_aaddr {
  uint8_t isused;
  uip_ipaddr_t ipaddr;
} uip_ds6_aaddr_t;


typedef struct uip_ds6_maddr {
  uint8_t isused;
  uip_ipaddr_t ipaddr;
} uip_ds6_maddr_t;
# 232 "../../../core/./net/uip-ds6.h"
typedef struct uip_ds6_netif {
  uint32_t link_mtu;
  uint8_t cur_hop_limit;
  uint32_t base_reachable_time;
  uint32_t reachable_time;
  uint32_t retrans_timer;
  uint8_t maxdadns;
  uip_ds6_addr_t addr_list[1 + 2];
  uip_ds6_aaddr_t aaddr_list[1 + 2 - 1 + 0];
  uip_ds6_maddr_t maddr_list[2 + 1 + 2 + 0];
} uip_ds6_netif_t;


typedef struct uip_ds6_element {
  uint8_t isused;
  uip_ipaddr_t ipaddr;
} uip_ds6_element_t;



extern uip_ds6_netif_t uip_ds6_if;
extern struct etimer uip_ds6_timer_periodic;


extern uip_ds6_prefix_t uip_ds6_prefix_list[1 + 2];







void uip_ds6_init(void);


void uip_ds6_periodic(void);



uint8_t uip_ds6_list_loop(uip_ds6_element_t *list, uint8_t size,
                          uint16_t elementsize, uip_ipaddr_t *ipaddr,
                          uint8_t ipaddrlen,
                          uip_ds6_element_t **out_element);



uip_ds6_nbr_t *uip_ds6_nbr_add(uip_ipaddr_t *ipaddr, uip_lladdr_t *lladdr,
                               uint8_t isrouter, uint8_t state);
void uip_ds6_nbr_rm(uip_ds6_nbr_t *nbr);
uip_ds6_nbr_t *uip_ds6_nbr_lookup(uip_ipaddr_t *ipaddr);
uip_ds6_nbr_t *uip_ds6_nbr_ll_lookup(uip_lladdr_t *lladdr);







uip_ds6_prefix_t *uip_ds6_prefix_add(uip_ipaddr_t *ipaddr, uint8_t length,
                                     uint8_t advertise, uint8_t flags,
                                     unsigned long vtime,
                                     unsigned long ptime);




void uip_ds6_prefix_rm(uip_ds6_prefix_t *prefix);
uip_ds6_prefix_t *uip_ds6_prefix_lookup(uip_ipaddr_t *ipaddr,
                                        uint8_t ipaddrlen);
uint8_t uip_ds6_is_addr_onlink(uip_ipaddr_t *ipaddr);





uip_ds6_addr_t *uip_ds6_addr_add(uip_ipaddr_t *ipaddr,
                                 unsigned long vlifetime, uint8_t type);
void uip_ds6_addr_rm(uip_ds6_addr_t *addr);
uip_ds6_addr_t *uip_ds6_addr_lookup(uip_ipaddr_t *ipaddr);
uip_ds6_addr_t *uip_ds6_get_link_local(int8_t state);
uip_ds6_addr_t *uip_ds6_get_global(int8_t state);





uip_ds6_maddr_t *uip_ds6_maddr_add(uip_ipaddr_t *ipaddr);
void uip_ds6_maddr_rm(uip_ds6_maddr_t *maddr);
uip_ds6_maddr_t *uip_ds6_maddr_lookup(uip_ipaddr_t *ipaddr);





uip_ds6_aaddr_t *uip_ds6_aaddr_add(uip_ipaddr_t *ipaddr);
void uip_ds6_aaddr_rm(uip_ds6_aaddr_t *aaddr);
uip_ds6_aaddr_t *uip_ds6_aaddr_lookup(uip_ipaddr_t *ipaddr);





void uip_ds6_set_addr_iid(uip_ipaddr_t *ipaddr, uip_lladdr_t *lladdr);


uint8_t get_match_length(uip_ipaddr_t *src, uip_ipaddr_t *dst);
# 348 "../../../core/./net/uip-ds6.h"
void uip_ds6_select_src(uip_ipaddr_t *src, uip_ipaddr_t *dst);
# 364 "../../../core/./net/uip-ds6.h"
uint32_t uip_ds6_compute_reachable_time(void);
# 51 "../../../core/./contiki-net.h" 2


# 1 "../../../core/./net/resolv.h" 1
# 47 "../../../core/./net/resolv.h"
 extern process_event_t resolv_event_found;


 void resolv_conf(const uip_ipaddr_t *dnsserver);
 uip_ipaddr_t *resolv_getserver(void);
 uip_ipaddr_t *resolv_lookup(const char *name);
 void resolv_query(const char *name);

extern struct process resolv_process;
# 54 "../../../core/./contiki-net.h" 2

# 1 "../../../core/./net/psock.h" 1
# 56 "../../../core/./contiki-net.h" 2

# 1 "../../../core/./net/rime.h" 1
# 48 "../../../core/./net/rime.h"
# 1 "../../../core/./net/rime/announcement.h" 1
# 69 "../../../core/./net/rime/announcement.h"
# 1 "../../../core/./net/rime/rimeaddr.h" 1
# 65 "../../../core/./net/rime/rimeaddr.h"
typedef union {
  unsigned char u8[8];
} rimeaddr_t;
# 79 "../../../core/./net/rime/rimeaddr.h"
void rimeaddr_copy(rimeaddr_t *dest, const rimeaddr_t *from);
# 93 "../../../core/./net/rime/rimeaddr.h"
int rimeaddr_cmp(const rimeaddr_t *addr1, const rimeaddr_t *addr2);
# 103 "../../../core/./net/rime/rimeaddr.h"
void rimeaddr_set_node_addr(rimeaddr_t *addr);
# 114 "../../../core/./net/rime/rimeaddr.h"
extern rimeaddr_t rimeaddr_node_addr;
# 127 "../../../core/./net/rime/rimeaddr.h"
extern const rimeaddr_t rimeaddr_null;
# 70 "../../../core/./net/rime/announcement.h" 2

struct announcement;

typedef void (*announcement_callback_t)(struct announcement *a,
     const rimeaddr_t *from,
     uint16_t id, uint16_t val);







struct announcement {
  struct announcement *next;
  uint16_t id;
  uint16_t value;
  announcement_callback_t callback;
  uint8_t has_value;
};
# 113 "../../../core/./net/rime/announcement.h"
void announcement_register(struct announcement *a,
      uint16_t id,
      announcement_callback_t callback);
# 127 "../../../core/./net/rime/announcement.h"
void announcement_remove(struct announcement *a);
# 140 "../../../core/./net/rime/announcement.h"
void announcement_set_value(struct announcement *a, uint16_t value);
# 152 "../../../core/./net/rime/announcement.h"
void announcement_remove_value(struct announcement *a);
# 167 "../../../core/./net/rime/announcement.h"
void announcement_bump(struct announcement *a);
# 183 "../../../core/./net/rime/announcement.h"
void announcement_listen(int periods);
# 199 "../../../core/./net/rime/announcement.h"
void announcement_init(void);
# 214 "../../../core/./net/rime/announcement.h"
struct announcement *announcement_list(void);
# 227 "../../../core/./net/rime/announcement.h"
void announcement_heard(const rimeaddr_t *from, uint16_t id, uint16_t value);
# 239 "../../../core/./net/rime/announcement.h"
void announcement_register_listen_callback(void (*callback)(int time));

enum {
  ANNOUNCEMENT_NOBUMP,
  ANNOUNCEMENT_BUMP,
};

typedef void (* announcement_observer)(uint16_t id, uint8_t has_value,
                                       uint16_t newvalue, uint16_t oldvalue,
                                       uint8_t bump);
# 264 "../../../core/./net/rime/announcement.h"
void announcement_register_observer_callback(announcement_observer observer);
# 49 "../../../core/./net/rime.h" 2
# 1 "../../../core/./net/rime/collect.h" 1
# 63 "../../../core/./net/rime/collect.h"
# 1 "../../../core/./net/rime/runicast.h" 1
# 81 "../../../core/./net/rime/runicast.h"
# 1 "../../../core/./net/rime/stunicast.h" 1
# 75 "../../../core/./net/rime/stunicast.h"
# 1 "../../../core/./sys/ctimer.h" 1
# 76 "../../../core/./net/rime/stunicast.h" 2
# 1 "../../../core/./net/rime/unicast.h" 1
# 65 "../../../core/./net/rime/unicast.h"
# 1 "../../../core/./net/rime/broadcast.h" 1
# 68 "../../../core/./net/rime/broadcast.h"
# 1 "../../../core/./net/rime/abc.h" 1
# 60 "../../../core/./net/rime/abc.h"
# 1 "../../../core/./net/packetbuf.h" 1
# 85 "../../../core/./net/packetbuf.h"
void packetbuf_clear(void);
# 98 "../../../core/./net/packetbuf.h"
void packetbuf_clear_hdr(void);

void packetbuf_hdr_remove(int bytes);
# 120 "../../../core/./net/packetbuf.h"
void *packetbuf_dataptr(void);
# 132 "../../../core/./net/packetbuf.h"
void *packetbuf_hdrptr(void);
# 145 "../../../core/./net/packetbuf.h"
uint8_t packetbuf_hdrlen(void);
# 164 "../../../core/./net/packetbuf.h"
uint16_t packetbuf_datalen(void);






uint16_t packetbuf_totlen(void);
# 181 "../../../core/./net/packetbuf.h"
void packetbuf_set_datalen(uint16_t len);
# 194 "../../../core/./net/packetbuf.h"
void packetbuf_reference(void *ptr, uint16_t len);
# 206 "../../../core/./net/packetbuf.h"
int packetbuf_is_reference(void);
# 219 "../../../core/./net/packetbuf.h"
void *packetbuf_reference_ptr(void);
# 235 "../../../core/./net/packetbuf.h"
void packetbuf_compact(void);
# 250 "../../../core/./net/packetbuf.h"
int packetbuf_copyfrom(const void *from, uint16_t len);
# 270 "../../../core/./net/packetbuf.h"
int packetbuf_copyto(void *to);
# 286 "../../../core/./net/packetbuf.h"
int packetbuf_copyto_hdr(uint8_t *to);
# 300 "../../../core/./net/packetbuf.h"
int packetbuf_hdralloc(int size);
# 314 "../../../core/./net/packetbuf.h"
int packetbuf_hdrreduce(int size);



typedef uint16_t packetbuf_attr_t;

struct packetbuf_attr {

  packetbuf_attr_t val;
};
struct packetbuf_addr {

  rimeaddr_t addr;
};







enum {
  PACKETBUF_ATTR_NONE,


  PACKETBUF_ATTR_CHANNEL,
  PACKETBUF_ATTR_NETWORK_ID,
  PACKETBUF_ATTR_LINK_QUALITY,
  PACKETBUF_ATTR_RSSI,
  PACKETBUF_ATTR_TIMESTAMP,
  PACKETBUF_ATTR_RADIO_TXPOWER,
  PACKETBUF_ATTR_LISTEN_TIME,
  PACKETBUF_ATTR_TRANSMIT_TIME,
  PACKETBUF_ATTR_MAX_MAC_TRANSMISSIONS,
  PACKETBUF_ATTR_MAC_SEQNO,
  PACKETBUF_ATTR_MAC_ACK,


  PACKETBUF_ATTR_RELIABLE,
  PACKETBUF_ATTR_PACKET_ID,
  PACKETBUF_ATTR_PACKET_TYPE,
  PACKETBUF_ATTR_REXMIT,
  PACKETBUF_ATTR_MAX_REXMIT,
  PACKETBUF_ATTR_NUM_REXMIT,
  PACKETBUF_ATTR_PENDING,


  PACKETBUF_ATTR_HOPS,
  PACKETBUF_ATTR_TTL,
  PACKETBUF_ATTR_EPACKET_ID,
  PACKETBUF_ATTR_EPACKET_TYPE,
  PACKETBUF_ATTR_ERELIABLE,


  PACKETBUF_ADDR_SENDER,
  PACKETBUF_ADDR_RECEIVER,
  PACKETBUF_ADDR_ESENDER,
  PACKETBUF_ADDR_ERECEIVER,

  PACKETBUF_ATTR_MAX
};
# 419 "../../../core/./net/packetbuf.h"
int packetbuf_set_attr(uint8_t type, const packetbuf_attr_t val);
packetbuf_attr_t packetbuf_attr(uint8_t type);
int packetbuf_set_addr(uint8_t type, const rimeaddr_t *addr);
const rimeaddr_t *packetbuf_addr(uint8_t type);


void packetbuf_attr_clear(void);

void packetbuf_attr_copyto(struct packetbuf_attr *attrs,
          struct packetbuf_addr *addrs);
void packetbuf_attr_copyfrom(struct packetbuf_attr *attrs,
     struct packetbuf_addr *addrs);
# 439 "../../../core/./net/packetbuf.h"
struct packetbuf_attrlist {
  uint8_t type;
  uint8_t len;
};
# 61 "../../../core/./net/rime/abc.h" 2
# 1 "../../../core/./net/rime/channel.h" 1
# 43 "../../../core/./net/rime/channel.h"
struct channel;



# 1 "../../../core/./net/rime/chameleon.h" 1
# 43 "../../../core/./net/rime/chameleon.h"
# 1 "../../../core/./net/rime/channel.h" 1
# 44 "../../../core/./net/rime/chameleon.h" 2

struct chameleon_module {
  struct channel *(* input)(void);
  int (* output)(struct channel *);
  int (* hdrsize)(const struct packetbuf_attrlist *);
};

void chameleon_init(void);

int chameleon_hdrsize(const struct packetbuf_attrlist attrlist[]);
struct channel *chameleon_parse(void);
int chameleon_create(struct channel *c);
# 48 "../../../core/./net/rime/channel.h" 2

struct channel {
  struct channel *next;
  uint16_t channelno;
  const struct packetbuf_attrlist *attrlist;
  uint8_t hdrsize;
};

struct channel *channel_lookup(uint16_t channelno);

void channel_set_attributes(uint16_t channelno,
       const struct packetbuf_attrlist attrlist[]);
void channel_open(struct channel *c, uint16_t channelno);
void channel_close(struct channel *c);
void channel_init(void);
# 62 "../../../core/./net/rime/abc.h" 2

struct abc_conn;







struct abc_callbacks {

  void (* recv)(struct abc_conn *ptr);
  void (* sent)(struct abc_conn *ptr, int status, int num_tx);
};

struct abc_conn {
  struct channel channel;
  const struct abc_callbacks *u;
};
# 98 "../../../core/./net/rime/abc.h"
void abc_open(struct abc_conn *c, uint16_t channel,
        const struct abc_callbacks *u);
# 111 "../../../core/./net/rime/abc.h"
void abc_close(struct abc_conn *c);
# 126 "../../../core/./net/rime/abc.h"
int abc_send(struct abc_conn *c);
# 137 "../../../core/./net/rime/abc.h"
void abc_input(struct channel *channel);

void abc_sent(struct channel *channel, int status, int num_tx);
# 69 "../../../core/./net/rime/broadcast.h" 2


struct broadcast_conn;
# 80 "../../../core/./net/rime/broadcast.h"
struct broadcast_callbacks {

  void (* recv)(struct broadcast_conn *ptr, const rimeaddr_t *sender);
  void (* sent)(struct broadcast_conn *ptr, int status, int num_tx);
};

struct broadcast_conn {
  struct abc_conn c;
  const struct broadcast_callbacks *u;
};
# 107 "../../../core/./net/rime/broadcast.h"
void broadcast_open(struct broadcast_conn *c, uint16_t channel,
        const struct broadcast_callbacks *u);
# 120 "../../../core/./net/rime/broadcast.h"
void broadcast_close(struct broadcast_conn *c);
# 135 "../../../core/./net/rime/broadcast.h"
int broadcast_send(struct broadcast_conn *c);
# 66 "../../../core/./net/rime/unicast.h" 2

struct unicast_conn;




struct unicast_callbacks {
  void (* recv)(struct unicast_conn *c, const rimeaddr_t *from);
  void (* sent)(struct unicast_conn *ptr, int status, int num_tx);
};

struct unicast_conn {
  struct broadcast_conn c;
  const struct unicast_callbacks *u;
};

void unicast_open(struct unicast_conn *c, uint16_t channel,
       const struct unicast_callbacks *u);
void unicast_close(struct unicast_conn *c);

int unicast_send(struct unicast_conn *c, const rimeaddr_t *receiver);
# 77 "../../../core/./net/rime/stunicast.h" 2
# 1 "../../../core/./net/queuebuf.h" 1
# 88 "../../../core/./net/queuebuf.h"
struct queuebuf;

void queuebuf_init(void);





struct queuebuf *queuebuf_new_from_packetbuf(void);

void queuebuf_update_attr_from_packetbuf(struct queuebuf *b);

void queuebuf_to_packetbuf(struct queuebuf *b);
void queuebuf_free(struct queuebuf *b);

void *queuebuf_dataptr(struct queuebuf *b);
int queuebuf_datalen(struct queuebuf *b);

rimeaddr_t *queuebuf_addr(struct queuebuf *b, uint8_t type);
packetbuf_attr_t queuebuf_attr(struct queuebuf *b, uint8_t type);

void queuebuf_debug_print(void);
# 78 "../../../core/./net/rime/stunicast.h" 2

struct stunicast_conn;



struct stunicast_callbacks {
  void (* recv)(struct stunicast_conn *c, const rimeaddr_t *from);
  void (* sent)(struct stunicast_conn *c, int status, int num_tx);
};

struct stunicast_conn {
  struct unicast_conn c;
  struct ctimer t;
  struct queuebuf *buf;
  const struct stunicast_callbacks *u;
  rimeaddr_t receiver;
};

void stunicast_open(struct stunicast_conn *c, uint16_t channel,
        const struct stunicast_callbacks *u);
void stunicast_close(struct stunicast_conn *c);

int stunicast_send_stubborn(struct stunicast_conn *c, const rimeaddr_t *receiver,
        clock_time_t rxmittime);
void stunicast_cancel(struct stunicast_conn *c);

int stunicast_send(struct stunicast_conn *c, const rimeaddr_t *receiver);

void stunicast_set_timer(struct stunicast_conn *c, clock_time_t t);

rimeaddr_t *stunicast_receiver(struct stunicast_conn *c);
# 82 "../../../core/./net/rime/runicast.h" 2

struct runicast_conn;







struct runicast_callbacks {
  void (* recv)(struct runicast_conn *c, const rimeaddr_t *from, uint8_t seqno);
  void (* sent)(struct runicast_conn *c, const rimeaddr_t *to, uint8_t retransmissions);
  void (* timedout)(struct runicast_conn *c, const rimeaddr_t *to, uint8_t retransmissions);
};

struct runicast_conn {
  struct stunicast_conn c;
  const struct runicast_callbacks *u;
  uint8_t sndnxt;
  uint8_t is_tx;
  uint8_t rxmit;
  uint8_t max_rxmit;
};

void runicast_open(struct runicast_conn *c, uint16_t channel,
        const struct runicast_callbacks *u);
void runicast_close(struct runicast_conn *c);

int runicast_send(struct runicast_conn *c, const rimeaddr_t *receiver,
    uint8_t max_retransmissions);

uint8_t runicast_is_transmitting(struct runicast_conn *c);
# 64 "../../../core/./net/rime/collect.h" 2
# 1 "../../../core/./net/rime/neighbor-discovery.h" 1
# 65 "../../../core/./net/rime/neighbor-discovery.h"
struct neighbor_discovery_conn;

struct neighbor_discovery_callbacks {
  void (* recv)(struct neighbor_discovery_conn *c,
  const rimeaddr_t *from, uint16_t val);
  void (* sent)(struct neighbor_discovery_conn *c);
};

struct neighbor_discovery_conn {
  struct broadcast_conn c;
  const struct neighbor_discovery_callbacks *u;
  struct ctimer send_timer, interval_timer;
  clock_time_t initial_interval, min_interval, max_interval;
  clock_time_t current_interval;
  uint16_t val;
};

void neighbor_discovery_open(struct neighbor_discovery_conn *c,
        uint16_t channel,
        clock_time_t initial,
        clock_time_t min,
        clock_time_t max,
        const struct neighbor_discovery_callbacks *u);
void neighbor_discovery_close(struct neighbor_discovery_conn *c);
void neighbor_discovery_set_val(struct neighbor_discovery_conn *c, uint16_t val);

void neighbor_discovery_start(struct neighbor_discovery_conn *c, uint16_t val);
# 65 "../../../core/./net/rime/collect.h" 2
# 1 "../../../core/./net/rime/collect-neighbor.h" 1
# 55 "../../../core/./net/rime/collect-neighbor.h"
# 1 "../../../core/./net/rime/collect-link-estimate.h" 1
# 61 "../../../core/./net/rime/collect-link-estimate.h"
struct collect_link_estimate {
  uint32_t etx_accumulator;
  uint8_t num_estimates;
};







void collect_link_estimate_new(struct collect_link_estimate *le);
# 84 "../../../core/./net/rime/collect-link-estimate.h"
void collect_link_estimate_update_tx(struct collect_link_estimate *le,
                                     uint8_t num_tx);
# 97 "../../../core/./net/rime/collect-link-estimate.h"
void collect_link_estimate_update_tx_fail(struct collect_link_estimate *le,
                                          uint8_t num_tx);
# 109 "../../../core/./net/rime/collect-link-estimate.h"
void collect_link_estimate_update_rx(struct collect_link_estimate *le);
# 118 "../../../core/./net/rime/collect-link-estimate.h"
uint16_t collect_link_estimate(struct collect_link_estimate *le);

int collect_link_estimate_num_estimates(struct collect_link_estimate *le);
# 56 "../../../core/./net/rime/collect-neighbor.h" 2
# 1 "../../../core/./lib/list.h" 1
# 57 "../../../core/./net/rime/collect-neighbor.h" 2

struct collect_neighbor_list {
  void *list_list; list_t list;
  struct ctimer periodic;
};

struct collect_neighbor {
  struct collect_neighbor *next;
  rimeaddr_t addr;
  uint16_t rtmetric;
  uint16_t age;
  uint16_t le_age;
  struct collect_link_estimate le;
  struct timer congested_timer;
};

void collect_neighbor_init(void);

list_t collect_neighbor_list(struct collect_neighbor_list *neighbor_list);

void collect_neighbor_list_new(struct collect_neighbor_list *neighbor_list);

int collect_neighbor_list_add(struct collect_neighbor_list *neighbor_list,
                              const rimeaddr_t *addr, uint16_t rtmetric);
void collect_neighbor_list_remove(struct collect_neighbor_list *neighbor_list,
                                  const rimeaddr_t *addr);
struct collect_neighbor *collect_neighbor_list_find(struct collect_neighbor_list *neighbor_list,
                                               const rimeaddr_t *addr);
struct collect_neighbor *collect_neighbor_list_best(struct collect_neighbor_list *neighbor_list);
int collect_neighbor_list_num(struct collect_neighbor_list *neighbor_list);
struct collect_neighbor *collect_neighbor_list_get(struct collect_neighbor_list *neighbor_list, int num);
void collect_neighbor_list_purge(struct collect_neighbor_list *neighbor_list);

void collect_neighbor_update_rtmetric(struct collect_neighbor *n,
                                      uint16_t rtmetric);
void collect_neighbor_tx(struct collect_neighbor *n, uint16_t num_tx);
void collect_neighbor_rx(struct collect_neighbor *n);
void collect_neighbor_tx_fail(struct collect_neighbor *n, uint16_t num_tx);
void collect_neighbor_set_congested(struct collect_neighbor *n);
int collect_neighbor_is_congested(struct collect_neighbor *n);

uint16_t collect_neighbor_link_estimate(struct collect_neighbor *n);
uint16_t collect_neighbor_rtmetric_link_estimate(struct collect_neighbor *n);
uint16_t collect_neighbor_rtmetric(struct collect_neighbor *n);
# 66 "../../../core/./net/rime/collect.h" 2
# 1 "../../../core/./net/packetqueue.h" 1
# 57 "../../../core/./net/packetqueue.h"
# 1 "../../../core/./lib/memb.h" 1
# 58 "../../../core/./net/packetqueue.h" 2
# 70 "../../../core/./net/packetqueue.h"
struct packetqueue {
  list_t *list;
  struct memb *memb;
};
# 86 "../../../core/./net/packetqueue.h"
struct packetqueue_item {
  struct packetqueue_item *next;
  struct queuebuf *buf;
  struct packetqueue *queue;
  struct ctimer lifetimer;
  void *ptr;
};
# 121 "../../../core/./net/packetqueue.h"
void packetqueue_init(struct packetqueue *q);
# 152 "../../../core/./net/packetqueue.h"
int packetqueue_enqueue_packetbuf(struct packetqueue *q, clock_time_t lifetime,
      void *ptr);
# 166 "../../../core/./net/packetqueue.h"
struct packetqueue_item *packetqueue_first(struct packetqueue *q);
# 179 "../../../core/./net/packetqueue.h"
void packetqueue_dequeue(struct packetqueue *q);
# 190 "../../../core/./net/packetqueue.h"
int packetqueue_len(struct packetqueue *q);
# 206 "../../../core/./net/packetqueue.h"
struct queuebuf *packetqueue_queuebuf(struct packetqueue_item *i);






void *packetqueue_ptr(struct packetqueue_item *i);
# 67 "../../../core/./net/rime/collect.h" 2
# 81 "../../../core/./net/rime/collect.h"
struct collect_callbacks {
  void (* recv)(const rimeaddr_t *originator, uint8_t seqno,
  uint8_t hops);
};
# 95 "../../../core/./net/rime/collect.h"
struct collect_conn {
  struct unicast_conn unicast_conn;



  struct announcement announcement;
  struct ctimer transmit_after_scan_timer;

  const struct collect_callbacks *cb;
  struct ctimer retransmission_timer;
  void *send_queue_list_list; list_t send_queue_list;
  struct packetqueue send_queue;
  struct collect_neighbor_list neighbor_list;

  struct ctimer keepalive_timer;
  clock_time_t keepalive_period;

  struct ctimer proactive_probing_timer;

  rimeaddr_t parent, current_parent;
  uint16_t rtmetric;
  uint8_t seqno;
  uint8_t sending, transmissions, max_rexmits;
  uint8_t eseqno;
  uint8_t is_router;

  clock_time_t send_time;
};

enum {
  COLLECT_NO_ROUTER,
  COLLECT_ROUTER,
};

void collect_open(struct collect_conn *c, uint16_t channels,
                  uint8_t is_router,
                  const struct collect_callbacks *callbacks);
void collect_close(struct collect_conn *c);

int collect_send(struct collect_conn *c, int rexmits);

void collect_set_sink(struct collect_conn *c, int should_be_sink);

int collect_depth(struct collect_conn *c);
const rimeaddr_t *collect_parent(struct collect_conn *c);

void collect_set_keepalive(struct collect_conn *c, clock_time_t period);

void collect_print_stats(void);
# 50 "../../../core/./net/rime.h" 2
# 1 "../../../core/./net/rime/ipolite.h" 1
# 101 "../../../core/./net/rime/ipolite.h"
struct ipolite_conn;
# 113 "../../../core/./net/rime/ipolite.h"
struct ipolite_callbacks {



  void (* recv)(struct ipolite_conn *c, const rimeaddr_t *from);




  void (* sent)(struct ipolite_conn *c);





  void (* dropped)(struct ipolite_conn *c);
};





struct ipolite_conn {
  struct broadcast_conn c;
  const struct ipolite_callbacks *cb;
  struct ctimer t;
  struct queuebuf *q;
  uint8_t hdrsize;
  uint8_t maxdups;
  uint8_t dups;
};
# 158 "../../../core/./net/rime/ipolite.h"
void ipolite_open(struct ipolite_conn *c, uint16_t channel, uint8_t maxdups,
    const struct ipolite_callbacks *cb);
# 168 "../../../core/./net/rime/ipolite.h"
void ipolite_close(struct ipolite_conn *c);
# 182 "../../../core/./net/rime/ipolite.h"
int ipolite_send(struct ipolite_conn *c, clock_time_t interval,
    uint8_t hdrsize);
# 192 "../../../core/./net/rime/ipolite.h"
void ipolite_cancel(struct ipolite_conn *c);
# 51 "../../../core/./net/rime.h" 2
# 1 "../../../core/./net/rime/mesh.h" 1
# 65 "../../../core/./net/rime/mesh.h"
# 1 "../../../core/./net/rime/multihop.h" 1
# 76 "../../../core/./net/rime/multihop.h"
struct multihop_conn;
# 85 "../../../core/./net/rime/multihop.h"
struct multihop_callbacks {
  void (* recv)(struct multihop_conn *ptr,
  const rimeaddr_t *sender,
  const rimeaddr_t *prevhop,
  uint8_t hops);
  rimeaddr_t *(* forward)(struct multihop_conn *ptr,
     const rimeaddr_t *originator,
     const rimeaddr_t *dest,
     const rimeaddr_t *prevhop,
     uint8_t hops);
};

struct multihop_conn {
  struct unicast_conn c;
  const struct multihop_callbacks *cb;
};

void multihop_open(struct multihop_conn *c, uint16_t channel,
      const struct multihop_callbacks *u);
void multihop_close(struct multihop_conn *c);
int multihop_send(struct multihop_conn *c, const rimeaddr_t *to);
void multihop_resend(struct multihop_conn *c, const rimeaddr_t *nexthop);
# 66 "../../../core/./net/rime/mesh.h" 2
# 1 "../../../core/./net/rime/route-discovery.h" 1
# 61 "../../../core/./net/rime/route-discovery.h"
# 1 "../../../core/./net/rime/netflood.h" 1
# 80 "../../../core/./net/rime/netflood.h"
struct netflood_conn;






struct netflood_callbacks {
  int (* recv)(struct netflood_conn *c, const rimeaddr_t *from,
        const rimeaddr_t *originator, uint8_t seqno, uint8_t hops);
  void (* sent)(struct netflood_conn *c);
  void (* dropped)(struct netflood_conn *c);
};

struct netflood_conn {
  struct ipolite_conn c;
  const struct netflood_callbacks *u;
  clock_time_t queue_time;
  rimeaddr_t last_originator;
  uint8_t last_originator_seqno;
};

void netflood_open(struct netflood_conn *c, clock_time_t queue_time,
      uint16_t channel, const struct netflood_callbacks *u);
void netflood_close(struct netflood_conn *c);

int netflood_send(struct netflood_conn *c, uint8_t seqno);
# 62 "../../../core/./net/rime/route-discovery.h" 2


struct route_discovery_conn;

struct route_discovery_callbacks {
  void (* new_route)(struct route_discovery_conn *c, const rimeaddr_t *to);
  void (* timedout)(struct route_discovery_conn *c);
};



struct route_discovery_conn {
  struct netflood_conn rreqconn;
  struct unicast_conn rrepconn;
  struct ctimer t;
  rimeaddr_t last_rreq_originator;
  uint16_t last_rreq_id;
  uint16_t rreq_id;
  const struct route_discovery_callbacks *cb;
};

void route_discovery_open(struct route_discovery_conn *c, clock_time_t time,
     uint16_t channels,
     const struct route_discovery_callbacks *callbacks);
int route_discovery_discover(struct route_discovery_conn *c, const rimeaddr_t *dest,
        clock_time_t timeout);

void route_discovery_close(struct route_discovery_conn *c);
# 67 "../../../core/./net/rime/mesh.h" 2

struct mesh_conn;




struct mesh_callbacks {

  void (* recv)(struct mesh_conn *c, const rimeaddr_t *from, uint8_t hops);

  void (* sent)(struct mesh_conn *c);

  void (* timedout)(struct mesh_conn *c);
};

struct mesh_conn {
  struct multihop_conn multihop;
  struct route_discovery_conn route_discovery_conn;
  struct queuebuf *queued_data;
  rimeaddr_t queued_data_dest;
  const struct mesh_callbacks *cb;
};
# 106 "../../../core/./net/rime/mesh.h"
void mesh_open(struct mesh_conn *c, uint16_t channels,
        const struct mesh_callbacks *callbacks);
# 119 "../../../core/./net/rime/mesh.h"
void mesh_close(struct mesh_conn *c);
# 134 "../../../core/./net/rime/mesh.h"
int mesh_send(struct mesh_conn *c, const rimeaddr_t *dest);
# 52 "../../../core/./net/rime.h" 2



# 1 "../../../core/./net/rime/polite-announcement.h" 1
# 62 "../../../core/./net/rime/polite-announcement.h"
void polite_announcement_init(uint16_t channel,
         clock_time_t min,
         clock_time_t max);
# 56 "../../../core/./net/rime.h" 2
# 1 "../../../core/./net/rime/polite.h" 1
# 100 "../../../core/./net/rime/polite.h"
struct polite_conn;
# 112 "../../../core/./net/rime/polite.h"
struct polite_callbacks {



  void (* recv)(struct polite_conn *c);




  void (* sent)(struct polite_conn *c);





  void (* dropped)(struct polite_conn *c);
};





struct polite_conn {
  struct abc_conn c;
  const struct polite_callbacks *cb;
  struct ctimer t;
  struct queuebuf *q;
  uint8_t hdrsize;
};
# 153 "../../../core/./net/rime/polite.h"
void polite_open(struct polite_conn *c, uint16_t channel,
   const struct polite_callbacks *cb);
# 163 "../../../core/./net/rime/polite.h"
void polite_close(struct polite_conn *c);
# 178 "../../../core/./net/rime/polite.h"
int polite_send(struct polite_conn *c, clock_time_t interval, uint8_t hdrsize);
# 187 "../../../core/./net/rime/polite.h"
void polite_cancel(struct polite_conn *c);
# 57 "../../../core/./net/rime.h" 2



# 1 "../../../core/./net/rime/rimestats.h" 1
# 43 "../../../core/./net/rime/rimestats.h"
struct rimestats {
  unsigned long tx, rx;

  unsigned long reliabletx, reliablerx,
    rexmit, acktx, noacktx, ackrx, timedout, badackrx;


  unsigned long toolong, tooshort, badsynch, badcrc;

  unsigned long contentiondrop,
    sendingdrop;

  unsigned long lltx, llrx;
};

extern struct rimestats rimestats;
# 61 "../../../core/./net/rime.h" 2
# 1 "../../../core/./net/rime/rmh.h" 1
# 71 "../../../core/./net/rime/rmh.h"
struct rmh_conn;







struct rmh_callbacks {
  void (* recv)(struct rmh_conn *ptr, rimeaddr_t *sender, uint8_t hops);
  rimeaddr_t *(* forward)(struct rmh_conn *ptr,
     const rimeaddr_t *originator,
     const rimeaddr_t *dest,
     const rimeaddr_t *prevhop,
     uint8_t hops);
};

struct rmh_conn {
  struct runicast_conn c;
  const struct rmh_callbacks *cb;
  uint8_t num_rexmit;
};

void rmh_open(struct rmh_conn *c, uint16_t channel,
       const struct rmh_callbacks *u);
void rmh_close(struct rmh_conn *c);
int rmh_send(struct rmh_conn *c, rimeaddr_t *to, uint8_t num_rexmit,
      uint8_t max_hops);
# 62 "../../../core/./net/rime.h" 2

# 1 "../../../core/./net/rime/route.h" 1
# 56 "../../../core/./net/rime/route.h"
struct route_entry {
  struct route_entry *next;
  rimeaddr_t dest;
  rimeaddr_t nexthop;
  uint8_t seqno;
  uint8_t cost;
  uint8_t time;

  uint8_t decay;
  uint8_t time_last_decay;
};

void route_init(void);
int route_add(const rimeaddr_t *dest, const rimeaddr_t *nexthop,
       uint8_t cost, uint8_t seqno);
struct route_entry *route_lookup(const rimeaddr_t *dest);
void route_refresh(struct route_entry *e);
void route_decay(struct route_entry *e);
void route_remove(struct route_entry *e);
void route_flush_all(void);
void route_set_lifetime(int seconds);

int route_num(void);
struct route_entry *route_get(int num);
# 64 "../../../core/./net/rime.h" 2
# 1 "../../../core/./net/rime/rucb.h" 1
# 45 "../../../core/./net/rime/rucb.h"
struct rucb_conn;

enum {
  RUCB_FLAG_NONE,
  RUCB_FLAG_NEWFILE,
  RUCB_FLAG_LASTCHUNK,
};

struct rucb_callbacks {
  void (* write_chunk)(struct rucb_conn *c, int offset, int flag,
         char *data, int len);
  int (* read_chunk)(struct rucb_conn *c, int offset, char *to,
       int maxsize);
  void (* timedout)(struct rucb_conn *c);
};



struct rucb_conn {
  struct runicast_conn c;
  const struct rucb_callbacks *u;
  rimeaddr_t receiver, sender;
  uint16_t chunk;
  uint8_t last_seqno;
  int last_size;
};

void rucb_open(struct rucb_conn *c, uint16_t channel,
       const struct rucb_callbacks *u);
void rucb_close(struct rucb_conn *c);

int rucb_send(struct rucb_conn *c, const rimeaddr_t *receiver);
# 65 "../../../core/./net/rime.h" 2

# 1 "../../../core/./net/rime/timesynch.h" 1
# 70 "../../../core/./net/rime/timesynch.h"
# 1 "../../../core/./net/mac/mac.h" 1
# 44 "../../../core/./net/mac/mac.h"
# 1 "../../../core/./dev/radio.h" 1
# 60 "../../../core/./dev/radio.h"
struct radio_driver {

  int (* init)(void);


  int (* prepare)(const void *payload, unsigned short payload_len);


  int (* transmit)(unsigned short transmit_len);


  int (* send)(const void *payload, unsigned short payload_len);


  int (* read)(void *buf, unsigned short buf_len);



  int (* channel_clear)(void);


  int (* receiving_packet)(void);


  int (* pending_packet)(void);


  int (* on)(void);


  int (* off)(void);
};


enum {
  RADIO_TX_OK,
  RADIO_TX_ERR,
  RADIO_TX_COLLISION,
  RADIO_TX_NOACK,
};
# 45 "../../../core/./net/mac/mac.h" 2


typedef void (* mac_callback_t)(void *ptr, int status, int transmissions);
# 60 "../../../core/./net/mac/mac.h"
struct mac_driver {
  char *name;


  void (* init)(void);


  void (* send)(mac_callback_t sent_callback, void *ptr);


  void (* input)(void);


  int (* on)(void);


  int (* off)(int keep_radio_on);


  unsigned short (* channel_check_interval)(void);
};


enum {

  MAC_TX_OK,



  MAC_TX_COLLISION,


  MAC_TX_NOACK,


  MAC_TX_DEFERRED,



  MAC_TX_ERR,




  MAC_TX_ERR_FATAL,
};
# 71 "../../../core/./net/rime/timesynch.h" 2
# 80 "../../../core/./net/rime/timesynch.h"
void timesynch_init(void);
# 90 "../../../core/./net/rime/timesynch.h"
rtimer_clock_t timesynch_time(void);
# 103 "../../../core/./net/rime/timesynch.h"
rtimer_clock_t timesynch_time_to_rtimer(rtimer_clock_t synched_time);
# 113 "../../../core/./net/rime/timesynch.h"
rtimer_clock_t timesynch_rtimer_to_time(rtimer_clock_t rtimer_time);
# 124 "../../../core/./net/rime/timesynch.h"
rtimer_clock_t timesynch_offset(void);
# 139 "../../../core/./net/rime/timesynch.h"
int timesynch_authority_level(void);





void timesynch_set_authority_level(int level);
# 67 "../../../core/./net/rime.h" 2
# 1 "../../../core/./net/rime/trickle.h" 1
# 68 "../../../core/./net/rime/trickle.h"
struct trickle_conn;

struct trickle_callbacks {
  void (* recv)(struct trickle_conn *c);
};

struct trickle_conn {
  struct broadcast_conn c;
  const struct trickle_callbacks *cb;
  struct ctimer t, interval_timer, first_transmission_timer;
  struct pt pt;
  struct queuebuf *q;
  clock_time_t interval;
  uint8_t seqno;
  uint8_t interval_scaling;
  uint8_t duplicates;
};

void trickle_open(struct trickle_conn *c, clock_time_t interval,
    uint16_t channel, const struct trickle_callbacks *cb);
void trickle_close(struct trickle_conn *c);

void trickle_send(struct trickle_conn *c);
# 68 "../../../core/./net/rime.h" 2
# 76 "../../../core/./net/rime.h"
int rime_init(void);
# 87 "../../../core/./net/rime.h"
void rime_input(void);

int rime_output(struct channel *c);

struct rime_sniffer {
  struct rime_sniffer *next;
  void (* input_callback)(void);
  void (* output_callback)(int mac_status);
};




void rime_sniffer_add(struct rime_sniffer *s);
void rime_sniffer_remove(struct rime_sniffer *s);

extern const struct network_driver rime_driver;


enum {
  RIME_OK,
  RIME_ERR,
  RIME_ERR_CONTENTION,
  RIME_ERR_NOACK,
};
# 58 "../../../core/./contiki-net.h" 2

# 1 "../../../core/./net/netstack.h" 1
# 100 "../../../core/./net/netstack.h"
# 1 "../../../core/./net/mac/rdc.h" 1
# 48 "../../../core/./net/mac/rdc.h"
struct rdc_buf_list {
  struct rdc_buf_list *next;
  struct queuebuf *buf;
  void *ptr;
};




struct rdc_driver {
  char *name;


  void (* init)(void);


  void (* send)(mac_callback_t sent_callback, void *ptr);


  void (* send_list)(mac_callback_t sent_callback, void *ptr, struct rdc_buf_list *list);


  void (* input)(void);


  int (* on)(void);


  int (* off)(int keep_radio_on);


  unsigned short (* channel_check_interval)(void);
};
# 101 "../../../core/./net/netstack.h" 2
# 1 "../../../core/./net/mac/framer.h" 1
# 46 "../../../core/./net/mac/framer.h"
struct framer {

  int (* create)(void);
  int (* parse)(void);

};
# 102 "../../../core/./net/netstack.h" 2





struct network_driver {
  char *name;


  void (* init)(void);


  void (* input)(void);
};

extern const struct network_driver sicslowpan_driver;
extern const struct rdc_driver nullrdc_driver;
extern const struct mac_driver csma_driver;
extern const struct radio_driver cc2530_rf_driver;
extern const struct framer framer_802154;

void netstack_init(void);
# 60 "../../../core/./contiki-net.h" 2
# 92 "../../../core/./net/psock.h" 2
# 101 "../../../core/./net/psock.h"
struct psock_buf {
  uint8_t *ptr;
  unsigned short left;
};







struct psock {
  struct pt pt, psockpt;


  const uint8_t *sendptr;
  uint8_t *readptr;

  uint8_t *bufptr;


  uint16_t sendlen;
  uint16_t readlen;

  struct psock_buf buf;

  unsigned int bufsize;

  unsigned char state;
};

void psock_init(struct psock *psock, uint8_t *buffer, unsigned int buffersize);
# 166 "../../../core/./net/psock.h"
char psock_send(struct psock *psock, const uint8_t *buf, unsigned int len);
# 200 "../../../core/./net/psock.h"
char psock_generator_send(struct psock *psock, unsigned short (*f)(void *), void *arg);
# 243 "../../../core/./net/psock.h"
char psock_readbuf_len(struct psock *psock, uint16_t len);
# 276 "../../../core/./net/psock.h"
char psock_readto(struct psock *psock, unsigned char c);
# 306 "../../../core/./net/psock.h"
uint16_t psock_datalen(struct psock *psock);
# 350 "../../../core/./net/psock.h"
char psock_newdata(struct psock *s);
# 38 "../../../core/net/psock.c" 2
# 1 "/usr/local/bin/../share/sdcc/include/stdio.h" 1 3 4
# 32 "/usr/local/bin/../share/sdcc/include/stdio.h" 3 4
# 1 "/usr/local/bin/../share/sdcc/include/stdarg.h" 1 3 4
# 53 "/usr/local/bin/../share/sdcc/include/stdarg.h" 3 4
typedef unsigned char __data * va_list;
# 33 "/usr/local/bin/../share/sdcc/include/stdio.h" 2 3 4





# 1 "/usr/local/bin/../share/sdcc/include/sdcc-lib.h" 1 3 4
# 46 "/usr/local/bin/../share/sdcc/include/sdcc-lib.h" 3 4
# 1 "/usr/local/bin/../share/sdcc/include/asm/mcs51/features.h" 1 3 4
# 47 "/usr/local/bin/../share/sdcc/include/sdcc-lib.h" 2 3 4
# 39 "/usr/local/bin/../share/sdcc/include/stdio.h" 2 3 4
# 49 "/usr/local/bin/../share/sdcc/include/stdio.h" 3 4
typedef void (*pfn_outputchar)(char c, void* p) __reentrant;

extern int _print_format (pfn_outputchar pfn, void* pvoid, const char *format, va_list ap);



extern void printf_small (char *,...) __reentrant;
extern int printf (const char *,...);
extern int vprintf (const char *, va_list);
extern int sprintf (char *, const char *, ...);
extern int vsprintf (char *, const char *, va_list);
extern int puts(const char *);
extern char *gets(char *);
extern char getchar(void);
extern void putchar(char);


extern void printf_fast(__code const char *fmt, ...) __reentrant;
extern void printf_fast_f(__code const char *fmt, ...) __reentrant;
extern void printf_tiny(__code const char *fmt, ...) __reentrant;
# 39 "../../../core/net/psock.c" 2
# 70 "../../../core/net/psock.c"
static void
buf_setup(struct psock_buf *buf,
   uint8_t *bufptr, uint16_t bufsize)
{
  buf->ptr = bufptr;
  buf->left = bufsize;
}

static uint8_t
buf_bufdata(struct psock_buf *buf, uint16_t len,
     uint8_t **dataptr, uint16_t *datalen)
{
  if(*datalen < buf->left) {
    memcpy(buf->ptr, *dataptr, *datalen);
    buf->ptr += *datalen;
    buf->left -= *datalen;
    *dataptr += *datalen;
    *datalen = 0;
    return 0;
  } else if(*datalen == buf->left) {
    memcpy(buf->ptr, *dataptr, *datalen);
    buf->ptr += *datalen;
    buf->left = 0;
    *dataptr += *datalen;
    *datalen = 0;
    return 1;
  } else {
    memcpy(buf->ptr, *dataptr, buf->left);
    buf->ptr += buf->left;
    *datalen -= buf->left;
    *dataptr += buf->left;
    buf->left = 0;
    return 1;
  }
}

static uint8_t
buf_bufto( struct psock_buf *buf, uint8_t endmarker,
   uint8_t **dataptr, uint16_t *datalen)
{
  uint8_t c;
  while(buf->left > 0 && *datalen > 0) {
    c = *buf->ptr = **dataptr;
    ++*dataptr;
    ++buf->ptr;
    --*datalen;
    --buf->left;

    if(c == endmarker) {
      return 2;
    }
  }

  if(*datalen == 0) {
    return 0;
  }

  while(*datalen > 0) {
    c = **dataptr;
    --*datalen;
    ++*dataptr;

    if(c == endmarker) {
      return 2 | 1;
    }
  }

  return 1;
}

static char
data_is_sent_and_acked( struct psock *s)
{



printf("[][]psock.c in data_is_sent_and_acked\n");
printf("[][]uip_mss is %d, sendlen is %d\n", (uip_conn->mss), s->sendlen);
  if(s->state != 6 || (uip_flags & 4)) {
    if(s->sendlen > (uip_conn->mss)) {
      uip_send(s->sendptr, (uip_conn->mss));
    } else {
      uip_send(s->sendptr, s->sendlen);
    }
    s->state = 6;
printf("[][]psock.c data sent return 0\n");
    return 0;
  } else if(s->state == 6 && (uip_flags & 1)) {
    if(s->sendlen > (uip_conn->mss)) {
      s->sendlen -= (uip_conn->mss);
      s->sendptr += (uip_conn->mss);
    } else {
      s->sendptr += s->sendlen;
      s->sendlen = 0;
    }
    s->state = 1;
printf("[][]psock.c data acked return 1, send len is %d\n", s->sendlen);
    return s->sendlen == 0;
  }
printf("[][]psock.c just return 0\n");
  return 0;
}

char psock_send( struct psock *s, const uint8_t *buf, unsigned int len)

{
  { char PT_YIELD_FLAG = 1; if (PT_YIELD_FLAG) {;} switch((&s->psockpt)->lc) { case 0:;
printf("[][]psock.c, in send\n");

  if(len == 0) {
    do { (&s->psockpt)->lc = 0;; return 2; } while(0);
  }



  s->sendptr = buf;
  s->sendlen = len;

  s->state = 0;



  while (s->sendlen > 0) {
printf("[][]psock.c send len is %d\n", s->sendlen);




    do { (&s->psockpt)->lc = 198; case 198:; if(!(data_is_sent_and_acked(s))) { return 0; } } while(0);
printf("[][]psock.c send len is %d\n", s->sendlen);


  }
printf("[][]psock.c send while loop over.");
  s->state = 0;

  }; PT_YIELD_FLAG = 0; (&s->psockpt)->lc = 0;; return 3; };
}

char psock_generator_send( struct psock *s, unsigned short (*generate)(void *), void *arg)

{
  { char PT_YIELD_FLAG = 1; if (PT_YIELD_FLAG) {;} switch((&s->psockpt)->lc) { case 0:;


  if(generate == (void *)0) {
    do { (&s->psockpt)->lc = 0;; return 2; } while(0);
  }

  s->state = 0;
  do {


    s->sendlen = generate(arg);
    s->sendptr = uip_appdata;

    if(s->sendlen > (uip_conn->mss)) {
      uip_send(s->sendptr, (uip_conn->mss));
    } else {
      uip_send(s->sendptr, s->sendlen);
    }
    s->state = 6;



    do { PT_YIELD_FLAG = 0; (&s->psockpt)->lc = 235; case 235:; if((PT_YIELD_FLAG == 0) || !((uip_flags & 1) || (uip_flags & 4))) { return 1; } } while(0);
  } while(!(uip_flags & 1));

  s->state = 0;

  }; PT_YIELD_FLAG = 0; (&s->psockpt)->lc = 0;; return 3; };
}

uint16_t
psock_datalen(struct psock *psock)
{
  return psock->bufsize - psock->buf.left;
}

char
psock_newdata(struct psock *s)
{
  if(s->readlen > 0) {


    return 1;
  } else if(s->state == 2) {

    s->state = 3;
    return 0;
  } else if((uip_flags & 2)) {

    return 1;
  } else {

    return 0;
  }
}

char psock_readto( struct psock *psock, unsigned char c)
{
  { char PT_YIELD_FLAG = 1; if (PT_YIELD_FLAG) {;} switch((&psock->psockpt)->lc) { case 0:;

  buf_setup(&psock->buf, psock->bufptr, psock->bufsize);




  do {
    if(psock->readlen == 0) {
      do { (&psock->psockpt)->lc = 280; case 280:; if(!(psock_newdata(psock))) { return 0; } } while(0);
      psock->state = 2;
      psock->readptr = (uint8_t *)uip_appdata;
      psock->readlen = uip_len;
    }
  } while((buf_bufto(&psock->buf, c,
       &psock->readptr,
       &psock->readlen) & 2) == 0);

  if(psock_datalen(psock) == 0) {
    psock->state = 0;
    do { (&psock->psockpt)->lc = 0;; return 0; } while(0);
  }
  }; PT_YIELD_FLAG = 0; (&psock->psockpt)->lc = 0;; return 3; };
}

char psock_readbuf_len( struct psock *psock, uint16_t len)
{
  { char PT_YIELD_FLAG = 1; if (PT_YIELD_FLAG) {;} switch((&psock->psockpt)->lc) { case 0:;

  buf_setup(&psock->buf, psock->bufptr, psock->bufsize);





  do {
    if(psock->readlen == 0) {
      do { (&psock->psockpt)->lc = 308; case 308:; if(!(psock_newdata(psock))) { return 0; } } while(0);
      psock->state = 2;
      psock->readptr = (uint8_t *)uip_appdata;
      psock->readlen = uip_len;
    }
  } while(buf_bufdata(&psock->buf, psock->bufsize,
        &psock->readptr, &psock->readlen) == 0 &&
   psock_datalen(psock) < len);

  if(psock_datalen(psock) == 0) {
    psock->state = 0;
    do { (&psock->psockpt)->lc = 0;; return 0; } while(0);
  }
  }; PT_YIELD_FLAG = 0; (&psock->psockpt)->lc = 0;; return 3; };
}


void
psock_init( struct psock *psock,
    uint8_t *buffer, unsigned int buffersize)
{
  psock->state = 0;
  psock->readlen = 0;
  psock->bufptr = buffer;
  psock->bufsize = buffersize;
  buf_setup(&psock->buf, buffer, buffersize);
  (&psock->pt)->lc = 0;;
  (&psock->psockpt)->lc = 0;;
}
