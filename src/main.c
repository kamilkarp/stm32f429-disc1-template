#include "stm32f4xx.h"
#include "system.h"


int main(void)
{
	System_Init();

	while(1){

		GPIO_WriteBit(GPIOG,GPIO_Pin_13,Bit_SET);
		USART_puts(USART1,"HELLO\n");
		delay_ms(500);
		GPIO_WriteBit(GPIOG,GPIO_Pin_13,Bit_RESET);
		delay_ms(500);
	}

	return 0;
}








