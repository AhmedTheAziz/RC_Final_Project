/*
 * op.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include "op.h"

uint8_t OP::CountA;
uint8_t OP::CountB;
uint8_t OP::CountC;
uint8_t OP::CountAF;

const unsigned int  Pause=0;

OP::OP(GPIO_TypeDef * GPIO, uint8_t pin, MODE mode) : Port_{GPIO}, Pin_{pin}, mode_{mode}
	{
			config port;

		if(GPIO == GPIOA)
		{
			if(mode == MODE::Gen)

		{
			if(CountA ==0)
			{
			port.ENPA();//enable RCC for port A
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
			if(CountAF==0)
			{
				//config port;
				port.AFIOP();
			CountAF++;
			}
			if(CountA ==0)
			{
				port.ENPA();//enable RCC for port A
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

	}
		else if(GPIO == GPIOB)
	{

		if(mode == MODE::Gen)

	{
		if(CountB ==0)
		{
			//config port;
			port.ENPB();//enable RCC for port B
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
		if(CountAF==0)
		{
			//config port;
			port.AFIOP();
			CountAF++;
		}
		if(CountB ==0)
		{
			config port;
			port.ENPB();//enable RCC for port B
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
	else if(GPIO == GPIOC)
		{

			if(mode == MODE::Gen)

		{
			if(CountC ==0)
			{
				//config port;
				port.ENPC();//enable RCC for port C
				Port_->CRL = 0x00000000;
				Port_->CRH = 0x00000000;
			}
			CountC++;
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
			if(CountAF==0)
			{
				//config port;
				port.AFIOP();
				CountAF++;
			}
			if(CountC ==0)
			{
				config port;
				port.ENPC();//enable RCC for port C
				Port_->CRL = 0x00000000;
				Port_->CRH = 0x00000000;
			}
			CountC++;
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
void OP::PWMON()
{
	tim3.pwmWrite();
}
void OP::PWMOFF()
{
	tim3.pwmWrite(Pause);
}
	OP::~OP()
	{
		OFF();
	}



