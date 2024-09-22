/*
 * uart.cpp
 *
 *  Created on: Sep 12, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "uart.h"

	UART::UART(int data)
	{
		if(this == reinterpret_cast<UART*>(UART1INS))
		{
			INIT(1);
		}
		else if (this == reinterpret_cast<UART*>(UART2INS))
		{
			INIT(2);
		}
		else if(this == reinterpret_cast<UART*>(UART3INS))
		{
			INIT(3);
		}
		else
		{
			Send(msg);
		}
	}
	void UART::INIT(int UART_NUMBER)
	{
		switch(UART_NUMBER)
		{
		case 1:
			//UART1 INITIATE
			// Activating Clock enable
			//              AFIO     GPIOA    USART1
			RCC->APB2ENR = (1<<0) | (1<<2) | (1<<14);
			//Activating TX(O/P PA9) and RX (I/P PA10) pins
			GPIOA->CRH = (0x000B<<4); // PA9 OutPut AFIO TX
			GPIOA->CRH = (4<<8); //PA10 InPut Floating RX
			// Setting BAUD Rate
			BRR = USART_div;
			//Enable Transmission and Receiving
			CR1= (1<<2) |(1<<3); //Receiver Enable || Transmitter Enable
			CR1|=(1<<13); // USART Enable
			break;

		case 2:
			//Enable Clock
			RCC->APB1ENR =(1<<17); // USART2
			//PA2(TX)[O/P] || PA3(RX)[I/P]
			RCC->APB2ENR |= (1<<0) | (1<<2); //  AFIO and PortA
			//Activate Tx & RX (PA2)& (PA3)
			GPIOA->CRL =(0x004B<<8);
			//Setting Baud Rate
			BRR=USART_div;
			//Enable Transmission and Receiving
			CR1= (1<<2) |(1<<3); //Receiver Enable || Transmitter Enable
			CR1|=(1<<13); // USART Enable

			break;
		case 3:
			//Enable Clock
			RCC->APB1ENR =(1<<18); // USART3
			// PB10 (Tx)[O/P] || PB11 (Rx)[I/P]
			RCC->APB2ENR |=(1<<0) | (1<<3); //AFIO & Port B
			//Activate Tx & RX (PB10)& (PB11)
			GPIOB->CRH =(0x004B<<8); //
			//Setting Baud Rate
			BRR=USART_div;
			//Enable Transmission and Receiving
			CR1= (1<<2) |(1<<3); //Receiver Enable || Transmitter Enable
			CR1|=(1<<13); // USART Enable
			break;
	}
	}
	char UART::Read()
	{
		while(!(SR&(1<<5))); //Bit 5 RXNE: Read data register not empty
		unsigned char mread=USART1->DR &0x00ff;
		return mread; //DR &0x00FF;
	}
	void UART::Send (char data)
	{
		unsigned char mread=USART1->DR=data &0x00FF;
		while(!(SR&(1<<7)));
	}
	void UART::Send(const std::string& data) // (std::string data) Succeed
	// (std::string_view data) // (char* data) Failed ??!
	{
		auto i{0};
		while(i!='\0')
		{
			Send(data[i]);
		}
	}
	void* UART::operator new(size_t, UART_Instance uart)
	{
		return reinterpret_cast<void*>(uart); // return uart-instance as a pointer not as an Address.
	}
