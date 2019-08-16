/*
 * LEDS.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Kamil
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

#define LD3_Port GPIOG
#define LD4_Port GPIOG

#define LD3_Pin GPIO_Pin_13
#define LD4_Pin GPIO_Pin_14

void LEDS_Init(void);


#endif /* LEDS_H_ */
