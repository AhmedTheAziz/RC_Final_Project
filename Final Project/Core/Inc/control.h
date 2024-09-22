/*
 * control.h
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_
#include "motor.h"

class Control
{
public:
	Control(Motor *m1,Motor *m2);
	void Forward();
	void Backward();
	void Right();
	void Left();
	void BREAK();
private:
	Motor * m1_;  // RHS Motor
	Motor * m2_;  // LHS Motor
};




#endif /* INC_CONTROL_H_ */
