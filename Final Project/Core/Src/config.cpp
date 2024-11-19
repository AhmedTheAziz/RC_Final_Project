/*
 * config.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include "config.h"

uint8_t config::Count;

/// <Constructor>
 config::config()
 {
	 if (Count ==0)
	 {
	 RCC->APB2ENR =0x00000000;
	 RCC->APB1ENR=0x00000000;
	 }
	 Count++;
 }

 /// <Enable Ports and AFIOs>
	 void config::ENPA()
	 {
		 RCC->APB2ENR |=(1<<2);
	 }
	 void config::ENPB()
	 {
		 RCC->APB2ENR |=(1<<3);
	 }
	 void config::ENPC()
	 {
		 RCC->APB2ENR |=(1<<4);
	 }
	 void config::AFIOP()
	 {
		 RCC->APB2ENR |=(1<<0);
	 }
	void config::TIM3EN()
	{
		RCC->APB1ENR |= (1<<1);
	}
  void config::UART1EN()
 {
	// PA8=CK, PA9=TX, PA10=RX
		//              AFIO     GPIOA    USART1
	RCC->APB2ENR |= (1<<0) | (1<<2) | (1<<14);

 }
 void config::UART2EN()
 {
	 config	afiop,porta; // PA0=CTS, PA1=RTS, PA2=TX, PA3=RX, PA4=CK
		afiop.AFIOP();
		porta.ENPA();
	 RCC->APB1ENR |=(1<<17);
 }
 void config::UART3EN()
 {
	 config	afiop,portb; // PB10=TX, PB11=RX,  PB12=CK, PB13=CTS, PB14=CTS
		afiop.AFIOP();
		portb.ENPB();
	 RCC->APB1ENR |=(1<<18);
 }

  /*void config::UART1rmap()
  {
  	  config afiop,portb,porta; // PB6 = TX , PB7 = RX
  	  afiop.AFIOP();
  	  porta.ENPA();
  	  portb.ENPB();
  	  RCC->APB2ENR |=(1<<14);
  }
  */


 ///<Destructor>
 config::~config()
		{

		}



