/*
 * usart.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Kamil
 */

#include "usart.h"


void USART_puts(USART_TypeDef *usart, volatile char* str){
	while(*str){
		//while(!(usart->SR & 0x040));
		while(USART_GetFlagStatus(usart,USART_FLAG_TC)==RESET );
			USART_SendData(usart,*str);
			*str++;

	}
}
