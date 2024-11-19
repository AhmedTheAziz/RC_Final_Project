/*
 * timer3.h
 *
 *  Created on: Nov 16, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_TIMER3_H_
#define INC_TIMER3_H_
#include "main.h"
#include "clock72.h"

class Timer3
{
public:
	/// <Constructor>
	Timer3()=default;
Timer3(unsigned int  PERIOD,unsigned int Duty);
	// Initiate Timer 3 CH 1&3 , Activate PWM.
void Tim3_Init(unsigned int  PERIOD);
void pwmWrite();
void pwmWrite(unsigned int duty);
void pwmWrite1(unsigned int duty);
void pwmWrite3(unsigned int duty);

//void enable_interrupt(IRQn_Type IRQn);
//void disable_interrupt(IRQn_Type IRQn);
	///<Destructor>
~Timer3();

private:
static unsigned int PERIOD/*=550*/;
unsigned int Duty/*=50*/;
static uint8_t Counttim;


};



#endif /* INC_TIMER3_H_ */
