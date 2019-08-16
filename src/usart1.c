/*
 * usart1.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Kamil
 */

#include "usart1.h"

void USART1_Init(void){
	RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_GPIOAEN,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_USART1EN,ENABLE);

	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode=GPIO_Mode_AF;
	gpio.GPIO_Pin=GPIO_Pin_9;
	gpio.GPIO_Speed=GPIO_Speed_100MHz;
	gpio.GPIO_OType=GPIO_OType_PP;
	gpio.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Init(GPIOA,&gpio);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	gpio.GPIO_Mode=GPIO_Mode_AF;
	gpio.GPIO_Pin=GPIO_Pin_10;
	gpio.GPIO_Speed=GPIO_Speed_100MHz;
	gpio.GPIO_OType=GPIO_OType_PP;
	gpio.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Init(GPIOA,&gpio);


	//USART_DeInit(USART1);
	USART_InitTypeDef usart;
	usart.USART_BaudRate=1000000;
	usart.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	usart.USART_Mode= USART_Mode_Rx | USART_Mode_Tx;
	usart.USART_Parity=USART_Parity_No;
	usart.USART_StopBits=USART_StopBits_1;
	usart.USART_WordLength=USART_WordLength_8b;
	//USART_OverSampling8Cmd(USART1,ENABLE);
	USART_Init(USART1,&usart);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	NVIC_InitTypeDef NVIC_InitStruct;
			NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
			NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
			NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 5;
			NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
			NVIC_Init(&NVIC_InitStruct);

	USART_Cmd(USART1,ENABLE);

	//USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
}

void USART1_IRQHandler(void){

	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)){
		volatile char tmp[2]={USART1->DR,'\0'};
		USART_puts(USART1,tmp);
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}

//	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)!=RESET){
//		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
//		dat=USART_ReceiveData(USART1);
//	}
//	else if (USART_GetITStatus(USART1,USART_IT_TC)!=RESET){
//
//		USART_ClearITPendingBit(USART1,USART_IT_TC);
//		USART_SendData(USART1,'y');
//	}
}



