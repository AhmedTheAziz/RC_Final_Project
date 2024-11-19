/*
 * control.h
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_
#include "motor.h"
#include "timer3.h"


class Control
{
public:
	Control(Motor *m1,Motor *m2);
	void Forward(unsigned int speed);
	void Backward(unsigned int speed);
	void Right(unsigned int speed);
	void Left(unsigned int speed);
	void BREAK();
private:
	Timer3 tim3;
	Motor * m1_;  // RHS Motor
	Motor * m2_;  // LHS Motor
};




#endif /* INC_CONTROL_H_ */
