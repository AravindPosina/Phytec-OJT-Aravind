#include"stm32f4xx.h"
void gpio(void)
{
	RCC->AHB1ENR = 1;
	//GPIOA->MODER &= ~0x00000c00;
	GPIOA->MODER |=0x00000400;
}
void ledon(void)
{
	GPIOA->ODR |= 0x00000020;
}
void ledoff(void)
{
	GPIOA->ODR &= ~0x00000020;
}

void delay(int n)
{
	int i;
	for(i=0;i<n*3195;i++);
}
