/*
 * motor.h
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_
#include "op.h"


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

	Motor(Moto_Config * config);
	void CW();   // in1 =1, in2=0, en=1
	void CCW();  // in1 =0, in2=1, en=1
	void STOP(); // in1 =x, in2=x, en=0

	Moto_Config * Config_;
};




#endif /* INC_MOTOR_H_ */
