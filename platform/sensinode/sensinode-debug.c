/**
 * \file
 *
 *   Definition of some debugging functions for the sensinode port.
 *
 *   This file is bankable, however, if placed outside HOME, putbank()
 *   becomes useless
 *
 *   putchar() uses uart1_writeb() which is in uart.c. uart.c is not bankable
 *   and should stay in HOME.
 *
 *   putstring() and puthex() are from msp430/watchdog.c
 *
 * \author
 *         George Oikonomou - <oikonomou@users.sourceforge.net>
 */

#include "cc2430_sfr.h"
#include "8051def.h"
#include "sensinode-debug.h"

static const char hexconv[] = "0123456789abcdef";
static const char binconv[] = "01";

/*---------------------------------------------------------------------------*/
void
putstring(char *s) __banked
{
  while(*s) {
    putchar(*s++);
  }
}
/*---------------------------------------------------------------------------*/
void
puthex(uint8_t c) __banked
{
  putchar(hexconv[c >> 4]);
  putchar(hexconv[c & 0x0f]);
}
/*---------------------------------------------------------------------------*/
void
putbin(uint8_t c) __banked
{
  unsigned char i = 0x80;
  while(i) {
    putchar(binconv[(c & i) != 0]);
    i >>= 1;
  }
}
/*---------------------------------------------------------------------------*/
void
putbank() __banked
{
  putchar('B');
  putchar('a');
  putchar('n');
  putchar('k');
  putchar(':');
  putchar(' ');
  putbin(PSBANK);
  putchar('\n');
}