#include "stm32f4xx.h"
void Enable(void)
{
	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 4;
	GPIOA->MODER &=~0x00000C00;
	GPIOA->MODER = 1<<10;
	GPIOC->MODER &= ~0x0C000000;
}

void swii(void)
{
	if(GPIOC->IDR & 0x2000)
		GPIOA->BSRR = 0x00200000;
	else
		GPIOA->BSRR = 0x00000020;
}
