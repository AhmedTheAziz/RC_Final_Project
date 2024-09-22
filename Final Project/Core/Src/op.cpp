/*
 * op.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include "op.h"

uint8_t OP::CountA;
uint8_t OP::CountB;

OP::OP(GPIO_TypeDef * GPIO, uint8_t pin, MODE mode) : Port_{GPIO}, Pin_{pin}, mode_{mode}
	{
		if(GPIO == GPIOA)
		{

			if(mode == MODE::Gen)

		{
			if(CountA ==0)
			{
				Port_->CRL = 0x00000000;
				Port_->CRH = 0x00000000;
			}
			CountA++;
			if(Pin_<PIN_per_REG)
			{
				Port_->CRL	|=(OP_50MHZ<<(Pin_ * BIT_per_PIN));
			}
			else
			{
				Port_->CRH |=(OP_50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
			}
		}

		else if (mode == MODE::AF)
		{
			if(CountA ==0)
			{
				Port_->CRL = 0x00000000;
				Port_->CRH = 0x00000000;
			}
			CountA++;
			if(Pin_<PIN_per_REG)
			{
				Port_->CRL	|=(OP_AF50MHZ<<(Pin_ * BIT_per_PIN));
			}
			else
			{
				Port_->CRH |=(OP_AF50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
			}
		}

	}		else if(GPIO == GPIOB)
	{

		if(mode == MODE::Gen)

	{
		if(CountB ==0)
		{
			Port_->CRL = 0x00000000;
			Port_->CRH = 0x00000000;
		}
		CountB++;
		if(Pin_<PIN_per_REG)
		{
			Port_->CRL	|=(OP_50MHZ<<(Pin_ * BIT_per_PIN));
		}
		else
		{
			Port_->CRH |=(OP_50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
		}
	}

	else if (mode == MODE::AF)
	{
		if(CountB ==0)
		{
			Port_->CRL = 0x00000000;
			Port_->CRH = 0x00000000;
		}
		CountB++;
		if(Pin_<PIN_per_REG)
		{
			Port_->CRL	|=(OP_AF50MHZ<<(Pin_ * BIT_per_PIN));
		}
		else
		{
			Port_->CRH |=(OP_AF50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
		}
	}

}
			OFF();
		}


	void OP::ON()
	{
		Port_->ODR|=(1<<Pin_);
	}
	void OP::OFF()
	{
		Port_->ODR&=~(1<<Pin_);
	}
	void OP::TOGGLE()
	{
		Port_->ODR ^=(1<<Pin_);
	}

	OP::~OP()
	{
		OFF();
	}



