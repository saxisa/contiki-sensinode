/*
 * Copyright (c) 2006, Swedish Institute of Computer Science
 * All rights reserved. 
 *
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
 */

/*
 * Small and portable implementation of a bit-banging I2C bus master.
 *
 * The code should port really easily to platforms other than the
 * msp430 but has some hardcoded constants in it.
 *
 * More info at:
 *   http://i2c-bus.org/
 *   http://www.esacademy.com/faq/i2c/
 */

#include <stdio.h>
#include <contiki.h>
//#include <dev/spi.h>

#include "dev/i2c.h"

#define I2C_PxDIR   P0DIR
#define I2C_PxIN    P0
#define I2C_PxOUT   P0
#define I2C_PxSEL   P0SEL
#define I2C_PxREN   P0INP
/*
 * SDA == P0.7
 * SCL == P0.6
 */
#define SDA       7
#define SCL       6

#define SET_SDA_OUT() {I2C_PxDIR |= BV(SDA); \
			I2C_PxREN |= BV(SDA); \
			}

#define SET_SDA_IN() {I2C_PxDIR &= ~BV(SDA); \
			I2C_PxREN &= ~BV(SDA);\
			I2C_PxOUT |=  BV(SDA); \
			}

#define SET_SCL_OUT() {I2C_PxDIR |= BV(SCL);\
			I2C_PxREN |= BV(SCL);\
			}
#define SET_SCL_IN()  {I2C_PxDIR &= ~BV(SCL); \
			I2C_PxREN &= ~BV(SCL);\
			I2C_PxOUT |=  BV(SCL); \
			}

#define SDA_0()  {SET_SDA_OUT();\
		I2C_PxOUT &= ~BV(SDA);\
		}

#define SDA_1()  {SET_SDA_OUT();\
		I2C_PxOUT |=  BV(SDA);\
		}

#define SDA_IS_1  (I2C_PxIN & BV(SDA))
#define SCL_IS_1  (I2C_PxIN & BV(SCL))

#define SCL_0()   {SET_SCL_OUT();\
		I2C_PxOUT &= ~BV(SCL);\
		}	/* SCL Output=0 */
#define SCL_1()   {SET_SCL_OUT();\
		I2C_PxOUT |=  BV(SCL);\
		}	/* SCL Output=1 */


/*
 * Should avoid infinite looping while waiting for SCL_IS_1. xxx/bg
 */
#define SCL_WAIT_FOR_1() {\
SET_SCL_IN();\
do{}while (!SCL_IS_1);\
}

#define delay_4_7us()  delay_us(5)

#define delay_4us()   delay_us(4)
static unsigned char old_pxsel, old_pxout, old_pxdir;

/*
 * Grab SDA and SCL pins for exclusive use but remember old
 * configuration so that it may be restored when we are done.
 */
void
i2c_enable(void)
{
  unsigned char sda_scl = BV(SDA)|BV(SCL);

  old_pxsel = I2C_PxSEL & sda_scl;
  old_pxout = I2C_PxOUT & sda_scl;
  old_pxdir = I2C_PxDIR & sda_scl;

 // spi_busy = 1;

  I2C_PxSEL &= ~sda_scl;

  I2C_PxOUT &= ~sda_scl;

  I2C_PxDIR |=  BV(SCL);		/* SCL Output */
  I2C_PxDIR &= ~BV(SDA);		/* SDA Input */
}

/*
 * Restore bus to what it was before i2c_enable.
 *
 */
void
i2c_disable(void)
{
  unsigned char not_sda_scl = ~(BV(SDA)|BV(SCL));

  I2C_PxDIR = (I2C_PxDIR & not_sda_scl) | old_pxdir;
  I2C_PxOUT = (I2C_PxOUT & not_sda_scl) | old_pxout;
  I2C_PxSEL = (I2C_PxSEL & not_sda_scl) | old_pxsel;

//  spi_busy = 0;
}

int
i2c_start(void)
{
  SDA_1();
  SCL_1();
#if 1
  SCL_WAIT_FOR_1();
#else
  {
    unsigned long n;
    for (n = 0; n < 100000 && !SCL_IS_1; n++)
      ;
    if (!SCL_IS_1)
      return -1;
  }
#endif
  delay_4_7us();
  SDA_0();
  delay_4us();
  SCL_0();
  delay_4us();
  return 0;
}

void
i2c_stop(void)
{
  SDA_0();
  delay_4us();
  SCL_1();
  SCL_WAIT_FOR_1();
  SDA_1();
  delay_4us();
}

/*
 * Return true if we received an ACK.
 */
uint8_t
i2c_write(unsigned _c)
{
  unsigned char c = _c;
  unsigned long n;
  int i;
  uint8_t ret;
  for (i = 0; i < 8; i++, c <<= 1) {
    if (c & 0x80)
      {SDA_1();}
    else
      {SDA_0();}
    SCL_1();
    SCL_WAIT_FOR_1();
    SCL_0();
    delay_4us();
  }


//  SDA_1();
  SCL_1();
  ret = 0;		   /* Loop waiting for an ACK to arrive. */
SET_SDA_IN();
  for (n = 0; n < 250000; n++) {
    if (!SDA_IS_1) {
      ret = 1;
      break;
    }
  }
  SCL_WAIT_FOR_1();		/* clock stretching? */
  SCL_0();
  delay_4us();
  return ret;
}

unsigned
i2c_read(int send_ack)
{
  int i;
  unsigned char c = 0x00;
SET_SDA_IN();
 // SDA_1();
  for (i = 0; i < 8; i++) {
    c <<= 1;
    SCL_1();

    SCL_WAIT_FOR_1();

    if (SDA_IS_1)
      c |= 0x1;
    SCL_0();
    delay_4us();
  }

  if (send_ack) {
    SDA_1();
  } else {
    SDA_0();
  }
  SCL_1();
  SCL_WAIT_FOR_1();
  SCL_0();
  return c;
}

uint8_t read_I2CM(uint8_t addrOfTargetSlave, uint8_t* buffer,
		int bufferLength) {
	int i;
//printf("[][]top of read_I2CM\n");
	addrOfTargetSlave <<= 1;
	addrOfTargetSlave |= 1; //set the last bit to 1, means read.

	/* 发送START信号 */
	i2c_start();

	/* 发送从设备地址，如果没回应则说明从设备不在�?*/
	if (i2c_write(addrOfTargetSlave) != 1) {
		printf("[][]read failed no device\n");
		i2c_stop();
		return 0;
	}

	/* 读除最后一个byte外的数，发送的是ACK信号 */
	for (i = 0; i < bufferLength - 1; i++) {
		buffer[i] = i2c_read(0);
	}

	buffer[bufferLength - 1] = i2c_read(1);
	/* 发送STOP信号 */
	i2c_stop();
//printf("[][]read success\n");
	return 1;
}

uint8_t write_I2CM(uint8_t addrOfTargetSlave, uint8_t* buffer,
		int bufferLength) {
	int i;
//printf("[][]top of write_I2CM\n");
	addrOfTargetSlave <<= 1;

	/* 发送START信号 */
	if (i2c_start() != 0) {
printf("[][]failed to i2c_start.\n");
	}

	/* 发送从设备地址，如果NoACK，表示从设备不存�?*/
	if (i2c_write(addrOfTargetSlave) != 1) {
printf("[][]failed to find device!\n");
		i2c_stop();
		return 0;
	}

	/* 写入前nBufLen-1字节 ，if error occurs while write any byte, return false immediately. */
	for (i = 0; i < bufferLength - 1; i++) {
		if (i2c_write(buffer[i]) != 1) {
			i2c_stop();
printf("[][]failed to write buffers!\n");
			return 0;
		}
	}

	/* 写入最后一个字节，不管SLAVE返回NACK或ACK均认为发送成�?*/
	i2c_write(buffer[bufferLength - 1]);

	/* 发送STOP信号 */
	i2c_stop();
//printf("[][]write success.\n");
	return 1;
}
