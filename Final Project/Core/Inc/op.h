/*
 * op.h
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_OP_H_
#define INC_OP_H_
#include "main.h"
#include "config.h"
#include "utils.h"
#include "timer3.h"
static constexpr uint32_t OP_50MHZ=3;
static constexpr uint32_t OP_AF50MHZ=0x0B;
enum class MODE :uint32_t
{
	Gen = OP_50MHZ,
	AF = OP_AF50MHZ
};
class OP
{
public:
	OP()=default;
	OP(GPIO_TypeDef * GPIO, uint8_t pin, MODE mode);
	void ON();
	void OFF();
	void TOGGLE();
	void PWMON();
	void PWMOFF();
	~OP();
private:
	GPIO_TypeDef * Port_;
	uint8_t Pin_;
	MODE mode_ ;
	/*inline*/ static uint8_t CountA;
	static uint8_t CountB;
	static uint8_t CountC;
	static uint8_t CountAF;
//static const unsigned int  Pause;
	Timer3 tim3;


};




#endif /* INC_OP_H_ */
