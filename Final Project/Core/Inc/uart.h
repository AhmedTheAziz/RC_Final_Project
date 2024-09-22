/*
 * uart.h
 *
 *  Created on: Sep 12, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include "main.h"
#include <string>
#include "config.h"
#include "ip.h"
#include "op.h"
/*
 * you can make a config struct to custome the frame size, transmission_mode and so on
 * then pass it to uart INIT()
 * struct UARTConfig
 * {
 * uint8_t Frame_size;
 * bool Transmission_mode;
 * };
 * const UARTConfig UART1Config
 * {
 * 8,
 * true
 * };
 * */
#include "main.h"
#include <string>
#include "op.h"
#include "ip.h"

#ifndef INC_UART_H_
#define INC_UART_H_

#define FOSC 8000000
#define BAUD 9600
enum UART_Instance : uint32_t
{
	UART1INS = 0x40013800,
	UART2INS = 0x40004400,
	UART3INS = 0x40004800,

};
const double USART_div = FOSC/(BAUD);
const std::string msg= "NO UART with this address is Available!! \r\n" ;

class UART
{
public:
	UART(int data);
	void INIT(int UART_NUMBER);
	char Read();
	void Send (char data);
	void Send(const std::string& data); // (std::string data) Succeed
	// (std::string_view data) // (char* data) Failed ??!

	void* operator new(size_t, UART_Instance uart);

private:

	//REGISTERS..
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GTPR;
};



#endif /* INC_UART_H_ */
