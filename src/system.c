/*
 * system.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Kamil
 */

#include "system.h"
#include "delay.h"
#include "LEDS.h"
#include "usart1.h"

void System_Init(void){
	SysClocks_Init();
	LEDS_Init();
	SysTick_Init();
	USART1_Init();
}

void SysClocks_Init(void){

	ErrorStatus HSEStartUpStatus;
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);
	HSEStartUpStatus=RCC_WaitForHSEStartUp();
	if(HSEStartUpStatus==SUCCESS){
		FLASH_PrefetchBufferCmd(ENABLE);
		FLASH_SetLatency(FLASH_Latency_6);
		//8/4=2  2*160=320  320/2=160=SYSCLCK  320/4=48
		//RCC_PLLConfig(RCC_PLLSource_HSE,4U,160U,8U,4U);
		RCC_PLLConfig(RCC_PLLSource_HSE,8,360,
				2,7);
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK2Config(RCC_HCLK_Div2);
		RCC_PCLK1Config(RCC_HCLK_Div4);
		RCC_PLLCmd(ENABLE);

		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource()!=0x08);

	}
	//RCC_APB1ENR_PWREN
	RCC_ClockSecuritySystemCmd(ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFGEN,ENABLE);

	PWR_OverDriveCmd(ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG,ENABLE);

	RCC_ClocksTypeDef clocks;
	RCC_GetClocksFreq(&clocks);

}

