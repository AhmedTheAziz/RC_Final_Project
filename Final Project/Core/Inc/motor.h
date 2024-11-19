/*
 * motor.h
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_
#include "op.h"
#include "timer3.h"


///<Struct for Pins to be configured as O/P
struct Moto_Config
{
	OP in1;
	OP in2;
	OP en;
};


///<class/Struct to Move a Single Motor>
struct Motor
{
	Motor()=default;
	Motor(Moto_Config * config);
	void CW();   // in1 =1, in2=0, en=Speed
	void CCW();  // in1 =0, in2=1, en=Speed
	void STOP(); // in1 =x, in2=x, en=Pause

	Moto_Config * Config_;
	Timer3 * Tim3;
};




#endif /* INC_MOTOR_H_ */
