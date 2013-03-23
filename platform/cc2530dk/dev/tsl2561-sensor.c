#include <stdlib.h>

#include "contiki.h"
#include "lib/sensors.h"
#include "dev/i2c.h"
#include "dev/tsl2561-sensor.h"
#include <stdio.h>
extern const struct sensors_sensor tsl2561_sensor;

enum {
	ON, OFF
};
static uint8_t state = OFF;

#define ADDR_TSL2561 0x29

static uint8_t CMD_ON_TSL2561[2] = { 0x80 , 0x03 };
static uint8_t CMD_OFF_TSL2561[2] = { 0x80 , 0x00 };
/**
 * 7-5 reserved
 * 4 GAIN: 1 means 16X, 0 means 1X
 * 3 Manual: manual timing control. Not used in SGR.
 * 2 reserved
 * 1-0: Integration Time. 00 13.7ms, 01 101ms, 10 402ms, 11: manually. SGR use 402ms(10).
 *
 * 0x81 is addr of TIMING register, the 2nd byte is the value to set the register.
 */
static uint8_t CMD_SET_TIMING_TSL2561[2] = { 0x81, BV(4) | BV(1) };

static uint8_t CMD_SET_INTERRUPT_TSL2561[2] = { 0x86, 0x00 };
static uint8_t CMD_READ_CH0_LOW_BYTE[1] = { 0x8C };
static uint8_t CMD_READ_CH0_HIGH_BYTE[1] = { 0x8D };
static uint8_t CMD_READ_CH1_LOW_BYTE[1] = { 0x8E };
static uint8_t CMD_READ_CH1_HIGH_BYTE[1] = { 0x8F };

/*---------------------------------------------------------------------------*/
#define ENSURE_SUCCESS(ret, cmd) \
	if (ret != 1) { \
		printf(cmd " fail\n"); \
	}

static int CalculateLux(uint16_t ch0, uint16_t ch1)
{
	long ratio = 0;
	uint16_t b, m;
	long channel0 = ch0;
	long channel1 = ch1;

	if (channel0 != 0) {
		ratio = channel1 << (RATIO_SCALE+1);
		ratio = ratio / channel0;
	}
	// round the ratio value
	ratio = (ratio + 1) >> 1;

	if ((ratio >= 0) && (ratio <= K1T))
	{b=B1T; m=M1T;}
	else if (ratio <= K2T)
	{b=B2T; m=M2T;}
	else if (ratio <= K3T)
	{b=B3T; m=M3T;}
	else if (ratio <= K4T)
	{b=B4T; m=M4T;}
	else if (ratio <= K5T)
	{b=B5T; m=M5T;}
	else if (ratio <= K6T)
	{b=B6T; m=M6T;}
	else if (ratio <= K7T)
	{b=B7T; m=M7T;}
	else if (ratio > K8T)
	{b=B8T; m=M8T;}
	ratio = (channel0 * b) - (channel1 * m);

	if (ratio < 0) ratio = 0;
	ratio += (1 << 13);
	return(ratio >> 14);
}

static int
value(int type)
{
	static uint8_t buffer[4];
	uint8_t succ;
	uint16_t ch0, ch1;
	switch(type) {
		case TSL2561_SENSOR_ILLUMINATION: 
			succ = write_I2CM(ADDR_TSL2561, CMD_READ_CH0_LOW_BYTE, 1);
			ENSURE_SUCCESS(succ, "write");

			succ = read_I2CM(ADDR_TSL2561, buffer, 1);
			ENSURE_SUCCESS(succ, "read");

			succ = write_I2CM(ADDR_TSL2561, CMD_READ_CH0_HIGH_BYTE, 1);
			ENSURE_SUCCESS(succ, "write");

			succ = read_I2CM(ADDR_TSL2561, buffer+1, 1);
			ENSURE_SUCCESS(succ, "read");

			succ = write_I2CM(ADDR_TSL2561, CMD_READ_CH1_LOW_BYTE, 1);
			ENSURE_SUCCESS(succ, "write");

			succ = read_I2CM(ADDR_TSL2561, buffer+2, 1);
			ENSURE_SUCCESS(succ, "read");

			succ = write_I2CM(ADDR_TSL2561, CMD_READ_CH1_HIGH_BYTE, 1);
			ENSURE_SUCCESS(succ, "write");

			succ = read_I2CM(ADDR_TSL2561, buffer+3, 1);
			ENSURE_SUCCESS(succ, "read");

			//printf("buffer is %d,%d,%d,%d \n",buffer[0], buffer[1], buffer[2], buffer[3]);
			ch0 = buffer[1]*256+buffer[0];
			ch1 = buffer[3]*256+buffer[2];

			return CalculateLux(ch0, ch1);
	}
	return 0;
}
/*---------------------------------------------------------------------------*/
	static int
status(int type)
{
	switch(type) {
		case SENSORS_ACTIVE:
		case SENSORS_READY:
			return (state == ON);
	}
	return 0;
}

/*---------------------------------------------------------------------------*/
	static int
configure(int type, int c)
{
	uint8_t succ = 0;
	switch(type) {
		case SENSORS_ACTIVE:
			if(c) {
				if(!status(SENSORS_ACTIVE)) {
					printf("activate\n");
					//printf("[][] going to start detecting\n");
					succ = write_I2CM(ADDR_TSL2561, CMD_ON_TSL2561, 2);
					ENSURE_SUCCESS(succ, "write");

					succ = write_I2CM(ADDR_TSL2561, CMD_SET_TIMING_TSL2561, 2);
					ENSURE_SUCCESS(succ, "write");

					succ = write_I2CM(ADDR_TSL2561, CMD_SET_INTERRUPT_TSL2561, 2);
					ENSURE_SUCCESS(succ, "write");
					state = ON;
				}
			} else {
				printf("deactivate\n");
				succ = write_I2CM(ADDR_TSL2561, CMD_OFF_TSL2561, 2);
				ENSURE_SUCCESS(succ, "write");
				state = OFF;
			}
	}
	return 0;
}
/*---------------------------------------------------------------------------*/
SENSORS_SENSOR(tsl2561_sensor, "tsl2561",
		value, configure, status);
