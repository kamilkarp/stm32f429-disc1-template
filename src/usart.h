/*
 * usart.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Kamil
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_it.h"

void USART_puts(USART_TypeDef *usart, volatile char* str);

#endif /* USART_H_ */
