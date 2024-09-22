/*
 * i2c.cpp
 *
 *  Created on: Sep 17, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "i2c.h"

void Set_Bit(uint32_t reg, uint8_t bit)
{
	reg|=(1<<bit);
}

uint32_t Get_Bit(uint32_t reg, uint8_t bit)
{
	return ((reg>>bit)&1);
}

I2C::I2C(I2C_TypeDef * pI2C, GPIO_TypeDef * pGpio) :mI2C(pI2C) ,gpio(pGpio)
	{

	}
	void I2C::I2C_INIT()
	{
		RCC->APB1ENR =(1<<21); //enable clock Gatting for i2c
	///<GPIO Configuration pins>
		mI2C->CR2 |=FREQ_8MHZ; //choosing Freq.
		Set_Bit(mI2C->CR1, START);
		mI2C->CCR =FREQ_8MHZ /2*mcal::I2C_Speed; //400KHZ
		mI2C->TRISE=0x09; //100/125ns=8+1 telling the processor i"m using 8MHZ for the rise time
		Set_Bit(mI2C->CR1,PE);
	}
	bool I2C::I2C_Generate_StartBit()
	{
		while(!(mI2C->SR1 &(1<<Start_Generated)));
		return true;
	}
	bool I2C::I2C_CheckReceived()
	{
		while(!(mI2C->SR1 &(1<<Received)));
		return true;
	}

	bool I2C::I2C_CheckTransmitted()
	{
		while(!(mI2C->SR1 &(1<<Transmitted)));
		return true;
	}
	uint8_t I2C::I2C_Transmit(uint8_t x)
	{
		return I2C_CheckTransmitted();
	}
	uint8_t I2C::I2C_Receive()
	{
		return I2C_CheckReceived() > 0? mI2C->DR :0;
	}


