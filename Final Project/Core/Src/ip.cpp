/*
 * ip.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include "ip.h"
uint32_t IP::Count;
	IP::IP(GPIO_TypeDef *GPIO, uint8_t Pin) : Port_(GPIO), Pin_(Pin)
	{
		if(Count==0)
		{
			Port_->CRL = 0x00000000;
			Port_->CRH = 0x00000000;
		}
		Count++;
		if(Pin_< PIN_per_REG)
		{
			Port_->CRL |=(IP_Floating<<(Pin_ * BIT_per_PIN));
		}
		else
		{
			Port_->CRH |=(IP_Floating<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
		}
	}
	uint32_t IP::getstats()
	{
		return Port_->IDR &(1<<Pin_);
	}

	IP::~IP()
	{

	}



