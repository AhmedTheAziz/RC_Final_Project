/*
 * ip.h
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_IP_H_
#define INC_IP_H_

#include"main.h"
#include "utils.h"
static constexpr uint32_t IP_Floating =4;
class IP
{
public:
	IP()=default;
	IP(GPIO_TypeDef *GPIO, uint8_t Pin);
	uint32_t getstats();
	~IP();
private:
	GPIO_TypeDef *Port_;
	uint8_t Pin_;
	/*inline*/ static uint32_t Count;

};




#endif /* INC_IP_H_ */
