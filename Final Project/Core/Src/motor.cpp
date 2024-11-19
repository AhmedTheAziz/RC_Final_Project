/*
 * motor.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "motor.h"

Motor::Motor(Moto_Config * config) : Config_{config}
{
STOP();
}

void Motor::CW()
{
	Config_->in1.ON();
	Config_->in2.OFF();
	//Config_->en.PWMON();
}
void Motor::CCW()
{
	Config_->in1.OFF();
	Config_->in2.ON();
	//Config_->en.PWMON();
}

void Motor::STOP()
{
	Config_->in1.OFF();
	Config_->in2.OFF();
	Config_->en.PWMOFF();
}
	///trying to merge op with timer pwm controlling....


