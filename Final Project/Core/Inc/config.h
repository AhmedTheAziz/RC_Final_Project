/*
 * config.h
 *
 *  Created on: Sep 10, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include "main.h"

class config
{
public:
/// <Constructor>
 config();
/// <Enable Ports and AFIOs>
 void ENPA();
 void ENPB();
 void ENPC();
 void AFIOP();
 void TIM3EN();
 void UART1EN();
 void UART2EN();
 void UART3EN();

/// void UART1rmap();

///<Destructor>
 ~config();

private:
	static uint8_t Count;

};



#endif /* INC_CONFIG_H_ */
