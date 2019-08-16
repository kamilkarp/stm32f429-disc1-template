#include "delay.h"

static __IO uint32_t sysTickCounter;

void SysTick_Init(void) {
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	while (SysTick_Config((uint32_t)180000000/(uint32_t)1000000) != 0) {
	}

}

void SysTick_Handler(void){
	TimeTick_Decrement();
}

void TimeTick_Decrement(void) {
	if (sysTickCounter != 0) {
		sysTickCounter--;
	}
}

void delay_us(uint32_t n) {
	sysTickCounter = n;
	while (sysTickCounter != 0) {
	}
}

void delay_1ms(void) {
	sysTickCounter = 1000;
	while (sysTickCounter != 0);
}

void delay_ms(uint32_t n) {
	while (n--) {
		delay_1ms();
	}
}

