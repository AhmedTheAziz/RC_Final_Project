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
	void Control::Forward()
	{
		m1_->CW();
		m2_->CCW();
	}
void Control::Backward()
{
	m2_->CW();
	m1_->CCW();
}
	void Control::Right()
	{
		m1_->STOP();
		m2_->CCW();

	}
	void Control::Left()
	{
		m1_->CW();
		m2_->STOP();
	}
	void Control::BREAK()
	{
		m1_->STOP();
		m2_->STOP();
	}

