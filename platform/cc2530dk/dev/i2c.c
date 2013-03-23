#include <stdio.h>
#include <stdlib.h>

#include "contiki.h"
#include "dev/i2c.h"
#define DELAY_1_HALFCYCLE_I2C()    delay_us(5)
#define DELAY_HALF_HALFCYCLE_I2C()    delay_us(2)
#define I2C_PORTSEL P0SEL
#define I2C_PORTOUT P0
#define I2C_PORTDIR P0DIR
#define I2C_PORTIN P0
#define I2C_PORTIE P0IE
#define I2C_PORTREN P0INP
#define I2C_SCL_BIT 6
#define I2C_SDA_BIT 7
#define SET_SDA_1_I2C()       {I2C_PORTOUT |=  BV(I2C_SDA_BIT);}
#define SET_SDA_0_I2C()       {I2C_PORTOUT &= ~BV(I2C_SDA_BIT);}
#define SET_SCL_1_I2C()       {I2C_PORTOUT |=  BV(I2C_SCL_BIT);}
#define SET_SCL_0_I2C()       {I2C_PORTOUT &= ~BV(I2C_SCL_BIT);}
#define SAMPLE_SDA_I2C     (I2C_PORTIN & BV(I2C_SDA_BIT))

#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0

#define PREPARE_SCL_I2C()     {\
		I2C_PORTDIR |=  BV(I2C_SCL_BIT); \
	}

#define RELEASE_SCL_I2C()      {\
		I2C_PORTDIR &= ~BV(I2C_SCL_BIT); \
	}

#define SWITCH_SDA_TO_OUT_I2C()     {\
		I2C_PORTDIR |=  BV(I2C_SDA_BIT); \
	}

#define SWITCH_SDA_TO_IN_I2C()      {\
		I2C_PORTDIR &= ~BV(I2C_SDA_BIT); \
	}

static void start_I2CM(void);
static void stop_I2CM(void);
static uint8_t writeByte_I2CM(uint8_t data);
static uint8_t readByte_I2CM(uint8_t isLastByte);

static void start_I2CM(void) {
	PREPARE_SCL_I2C();
	SWITCH_SDA_TO_OUT_I2C();

	SET_SDA_1_I2C();
	SET_SCL_1_I2C();
	DELAY_1_HALFCYCLE_I2C();
	DELAY_1_HALFCYCLE_I2C();

	SET_SDA_0_I2C();
	DELAY_HALF_HALFCYCLE_I2C();

	SET_SCL_0_I2C();
	DELAY_HALF_HALFCYCLE_I2C();
}

static void stop_I2CM(void) {
	SWITCH_SDA_TO_OUT_I2C();
	SET_SDA_0_I2C();
	DELAY_1_HALFCYCLE_I2C();

	SET_SCL_1_I2C();
	DELAY_HALF_HALFCYCLE_I2C();

	SET_SDA_1_I2C();
	DELAY_HALF_HALFCYCLE_I2C();

	SWITCH_SDA_TO_IN_I2C();
	RELEASE_SCL_I2C();
}

static uint8_t writeByte_I2CM(uint8_t data) {
	uint8_t i;
	uint8_t rlt;
	SWITCH_SDA_TO_OUT_I2C();
	for (i = 0; i < 8; i++) {
		if ((data >> 7) & 0x01) {
			SET_SDA_1_I2C();
		} else {
			SET_SDA_0_I2C();
		}

		SET_SCL_1_I2C();
		DELAY_1_HALFCYCLE_I2C();

		SET_SCL_0_I2C();

		/* 前面的bit可以等下周期时钟开始前再写SDA，但最后一bit应提前释放，留给上拉时间 */
		if(i == 7)
			break;

		DELAY_1_HALFCYCLE_I2C();
		data = data << 1;
	}

	/* 最后一个bit的后半周期，SCL已经拉低 */
	SWITCH_SDA_TO_IN_I2C();
	DELAY_1_HALFCYCLE_I2C();

	SET_SCL_1_I2C();
	DELAY_HALF_HALFCYCLE_I2C();

	rlt = FAILURE;
	if (SAMPLE_SDA_I2C == 0)
		rlt = SUCCESS;

	DELAY_HALF_HALFCYCLE_I2C();
	SET_SCL_0_I2C();
	DELAY_1_HALFCYCLE_I2C();

	return rlt;
}

static uint8_t readByte_I2CM(uint8_t isLastByte) {
	uint8_t tempData = 0;
	uint8_t i;
	SWITCH_SDA_TO_IN_I2C();
	for (i = 0; i < 8; i++) {
		SET_SCL_1_I2C();
		DELAY_HALF_HALFCYCLE_I2C();
		if (SAMPLE_SDA_I2C) {
			tempData |= 1;
		}
		DELAY_HALF_HALFCYCLE_I2C();

		SET_SCL_0_I2C();

		/* 前面的bit可以等下周期时钟开始前再写SDA，但最后一bit应提前释放，留给上拉时间 */
		if(i == 7)
			break;

		DELAY_1_HALFCYCLE_I2C();

		tempData = tempData << 1;
	}

	SWITCH_SDA_TO_OUT_I2C();
	DELAY_1_HALFCYCLE_I2C();

	//write ACK.
	if(isLastByte == TRUE)
		{SET_SDA_1_I2C();}
	else
		{SET_SDA_0_I2C();}

	SET_SCL_1_I2C();
	DELAY_1_HALFCYCLE_I2C();
	SET_SCL_0_I2C();
	DELAY_1_HALFCYCLE_I2C();

	return tempData;
}

uint8_t read_I2CM(uint8_t addrOfTargetSlave, uint8_t* buffer,
		int bufferLength) {
int i;
	addrOfTargetSlave <<= 1;
	addrOfTargetSlave |= 1; //set the last bit to 1, means read.

	/* 发送START信号 */
	start_I2CM();

	if (writeByte_I2CM(addrOfTargetSlave) != TRUE) {
		stop_I2CM();
		return FAILURE;
	}

	/* 读除最后一个byte外的数，发送的是ACK信号 */
	for (i = 0; i < bufferLength - 1; i++) {
		buffer[i] = readByte_I2CM(FALSE);
	}

	buffer[bufferLength - 1] = readByte_I2CM(TRUE);

	/* 发送STOP信号 */
	stop_I2CM();
	return SUCCESS;
}

uint8_t write_I2CM(uint8_t addrOfTargetSlave, uint8_t* buffer,
		int bufferLength) {
	int i;
	addrOfTargetSlave <<= 1;

	/* 发送START信号 */
	start_I2CM();

	if (writeByte_I2CM(addrOfTargetSlave) != SUCCESS) {
		stop_I2CM();
		printf("[][]fail to find device\n");
		return FAILURE;
	}

	/* 写入前nBufLen-1字节 ，if error occurs while write any byte, return false immediately. */
	for (i = 0; i < bufferLength - 1; i++) {
		if (writeByte_I2CM(buffer[i]) != SUCCESS) {
			stop_I2CM();
			printf("[][]fail to write all\n");
			return FAILURE;
		}
	}


	writeByte_I2CM(buffer[bufferLength - 1]);

	/* 发送STOP信号 */
	stop_I2CM();
	return SUCCESS;
}

