/*
 * op.h
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_OP_H_
#define INC_OP_H_
#include "main.h"
#include "utils.h"
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

	~OP();
private:
	GPIO_TypeDef * Port_;
	uint8_t Pin_;
	MODE mode_ ;
	/*inline*/ static uint8_t CountA;
	static uint8_t CountB;
};




#endif /* INC_OP_H_ */
