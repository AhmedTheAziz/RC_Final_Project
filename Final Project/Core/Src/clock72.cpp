/*
 * clock72.cpp
 *
 *  Created on: Nov 16, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "clock72.h"
uint8_t Clock72::Countclk;
 Clock72::Clock72 ()
 {
	 if(Countclk==0)
	 {
	 Clock_Init();
 }
	 Countclk++;
 }
void Clock72::Clock_Init()
	{
		//Adding wait states to memory reads.
		FLASH->ACR	= 0x12;	// for system clock between 48 and 72MHz
		RCC->CR |= (1<<16);	//HSE on
		while (!(RCC->CR & (1<<17)));	//wait until HSE ready
		RCC->CR |= (1<<26);	//PLL2 on (test)25
		RCC->CFGR |= (1<<16);
		RCC->CFGR |= (7<<18);	// mult by 9	--->72MHz
		RCC->CFGR |= (1<<10);	//APB1 = 36MHz. See bus clocks.
		RCC->CR |= (1<<24);	//enable PLL
		while (!(RCC->CR & (1<<25)));	//wait until locked
		RCC->CFGR |= (2<<0);	//PLL as clock source
	}
