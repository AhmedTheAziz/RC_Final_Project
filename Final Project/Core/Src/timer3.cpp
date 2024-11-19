/*
 * timer3.cpp
 *
 *  Created on: Nov 16, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "timer3.h"
uint8_t Timer3::Counttim;
unsigned int Timer3::PERIOD=0;

Timer3::Timer3(unsigned int  Period,unsigned int  duty)  :		Duty{duty}
	{
		PERIOD=Period;

	if(Counttim==0)
	{
		Tim3_Init(PERIOD);
	}
	Counttim++;
	}

void Timer3::Tim3_Init(unsigned int PERIOD)
{

	///<Intiate Clock 72>
	Clock72 clk;
	///<Enable Timer 3 RCC>
	RCC->APB1ENR |= (1<<1);
	///<Reset Control Register just in case>
	TIM3->CR1=0x0000;
	///<Set Pre-scaler>
	TIM3->PSC=71; // 72 / 71 +1 = 1MHZ timer clock speed.
	///<Set Period>
	TIM3->ARR =PERIOD;
	///<Select PWM>
	 //<Preload Enable & PWM Mode 1 for CH1>
	 TIM3->CCMR1|= (8<<0) |(6<<4);
     //<Preload Enable & PWM Mode 1 for CH3>
	 TIM3->CCMR2 |=(8<<0) |(6<<4);
	///<Enable CH's and Polarity (Active-High)>
	 //<Enable CH1 & CH3>
	 TIM3->CCER =(1<<0)|(1<<8);
    ///<Enable Control Register>
	 TIM3->CR1|=(1<<0);
}

void Timer3::pwmWrite()
{
	///<Making sure duty stays between 0% & 100%>
	if(Duty < 0)
	{
		Duty =0;
	}
	else if (Duty > 100)
	{
		Duty=100;
	}
	unsigned int PulseWidth = PERIOD * Duty/100;
	TIM3->CCR1=PulseWidth;
	TIM3->CCR3=PulseWidth;
}

void Timer3::pwmWrite(unsigned int duty)
{
	Duty=duty;
	///<Making sure duty stays between 0% & 100%>
	if(Duty < 0)
	{
		Duty =0;
	}
	else if (Duty > 100)
	{
		Duty=100;
	}
	unsigned int PulseWidth = PERIOD * Duty/100;
	TIM3->CCR1=PulseWidth;
	TIM3->CCR3=PulseWidth;
}
void Timer3::pwmWrite1(unsigned int duty)
{
	Duty=duty;
	///<Making sure duty stays between 0% & 100%>
	if(Duty < 0)
	{
		Duty =0;
	}
	else if (Duty > 100)
	{
		Duty=100;
	}
	unsigned int PulseWidth = PERIOD * Duty/100;
	TIM3->CCR1=PulseWidth;
}
void Timer3::pwmWrite3(unsigned int duty)
{
	Duty=duty;
	///<Making sure duty stays between 0% & 100%>
	if(Duty < 0)
	{
		Duty =0;
	}
	else if (Duty > 100)
	{
		Duty=100;
	}
	unsigned int PulseWidth = PERIOD * Duty/100;
	TIM3->CCR3=PulseWidth;
}

Timer3::~Timer3()
{

}

