/*
 * i2c.c
 *
 *  Created on: Sep 2, 2024
 *      Author: hector.torre
 */

#include "I2C.h"

void I2C_WriteRegister(unsigned char u8SlaveAddress, unsigned char u8RegisterAddress, unsigned char u8Data)
{
	I2C_Start();
	I2C0->D = u8SlaveAddress << 1; // Send I2C device address with W/R bit = 0
	I2C_Wait();

	I2C0->D = u8RegisterAddress; // Send register address
	I2C_Wait();

	I2C0->D = u8Data;			// Send the data
	I2C_Wait();

	I2C_Stop();

    Pause(50);
}

unsigned char I2C_ReadRegister(unsigned char u8SlaveAddress, unsigned char u8RegisterAddress)
{
	unsigned char result;

	I2C_Start();
	I2C0->D = u8SlaveAddress << 1; //Send I2C device address with W/R bit = 0
	I2C_Wait();

	I2C0->D = u8RegisterAddress; // Send register address
	I2C_Wait();

	I2C_RepeatedStart();

	I2C0->D = (u8SlaveAddress << 1) | 0x01; // Send I2C device address this time with W/R bit = 1
	I2C_Wait();

	I2C_EnterRxMode();
	I2C_DisableAck();

	result = I2C0->D;
	I2C_Wait();
	I2C_Stop();
	result = I2C0->D;
	Pause(50);
	return result;
}

void I2C_ReadMultiRegisters(unsigned char u8SlaveAddress, unsigned char u8RegisterAddress, unsigned char n, unsigned char *r)
{
	char i;

	I2C_Start();
	I2C0->D = u8SlaveAddress << 1;	//Send I2C device address with W/R bit = 0
	I2C_Wait();

	I2C0->D = u8RegisterAddress;	// Send register address
	I2C_Wait();

	I2C_RepeatedStart();

	I2C0->D = (u8SlaveAddress << 1) | 0x01;	// Send I2C device address this time with W/R bit = 1
	I2C_Wait();

	I2C_EnterRxMode();
	I2C_EnableAck();

	i = I2C0->D;
	I2C_Wait();

	for(i=0; i<n-2; i++)
	{
	    *r = I2C0->D;
	    r++;
	    I2C_Wait();
	}

	I2C_DisableAck();
	*r = I2C0->D;
	r++;
	I2C_Wait();
	I2C_Stop();
	*r = I2C0->D;
	Pause(50);
}

void Pause(int number)
{
	int cnt;
	for(cnt=0; cnt<number; cnt++)
	{
		asm("nop");
	};
}

