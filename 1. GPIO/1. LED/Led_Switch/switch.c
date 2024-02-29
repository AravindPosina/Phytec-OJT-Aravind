
#include"stm32f4xx.h"



void enable(void)
{
	RCC->AHB1ENR |=1;
	RCC->AHB1ENR |=4;
	GPIOA->MODER |=1<<10;
	GPIOC->MODER =0;

}


void swii(void)
{
	if(GPIOC->IDR &= 0x2000)
		GPIOA->BSRR |=0x00000020;

	else
		GPIOA->BSRR |=0x00200000;


}

