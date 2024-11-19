/*
 * control.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "control.h"
	Control::Control(Motor *m1,Motor *m2) : m1_{m1},m2_{m2}
	{
		m1_->STOP();
		m2_->STOP();
		//BREAK();
	}
	void Control::Forward(unsigned int speed)
	{
		m1_->CW();
		m2_->CCW();
		tim3.pwmWrite(speed);
	}
	void Control::Backward(unsigned int speed)
	{
		m2_->CW();
		m1_->CCW();
		tim3.pwmWrite(speed);
	}
	void Control::Right(unsigned int speed)
	{
		m1_->STOP();
		m2_->CCW();
		tim3.pwmWrite3(speed);

	}
	void Control::Left(unsigned int speed)
	{
		m1_->CW();
		m2_->STOP();
		tim3.pwmWrite1(speed);
	}
	void Control::BREAK()
	{
		m1_->STOP();
		m2_->STOP();
	}

