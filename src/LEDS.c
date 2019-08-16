/*
 * LEDS.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Kamil
 */

#include "LEDS.h"

void LEDS_Init(void){
	GPIO_DeInit(LD3_Port);
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Speed=GPIO_Speed_100MHz;
	gpio.GPIO_PuPd=GPIO_PuPd_NOPULL;
	gpio.GPIO_Mode=GPIO_Mode_OUT;
	gpio.GPIO_OType=GPIO_OType_PP;
	gpio.GPIO_Pin=LD3_Pin | LD4_Pin;
	GPIO_Init(LD3_Port,&gpio);
}

