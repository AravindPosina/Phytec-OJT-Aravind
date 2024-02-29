#include<stdio.h>
int main(void)
{
	RCC->>AHB1ENR |=GPIPOAEN; /* enable GPIOA clock */

	GPIOA->MODER &= ~00000C00; /* clear pin mode */
	GPIOA->MODER |=0x00000400; /* set pin to output mode */

	tim2_1hz_init();
	while(1)
	{
		tim_delay();
		GPIOA->ODR ^= LED; /* turn on LED */

	}
}
