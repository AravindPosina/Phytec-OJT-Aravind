#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

//#include "exti.h"

#define LINE13  				(1<<13)


#define GPIOAEN				   (1U<<0)
#define PIN5				   (1U<<5)

#define LED				   		PIN5

void pc13_exti_init(void);
static void exti_callback(void);


int main(void)
{


	//1.Enable clock access to GPIOA/
	RCC->AHB1ENR |= GPIOAEN;

	//2.Set PA5 as output pin/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);



	pc13_exti_init();



	while(1)
	{



	}

}


static void exti_callback(void)
{
	printf("BTN Pressed...\n\r");
	GPIOA->ODR ^=LED;
}


void EXTI15_10_IRQHandler(void) {
	if((EXTI->PR & LINE13)!=0)
	{
		//Clear PR flag
		EXTI->PR |=LINE13;
		//Do something...
		exti_callback();
	}

}


#define GPIOCEN		    (1U<<2)
#define SYSCFGEN		(1U<<14)

void pc13_exti_init(void)
{
	//Disable global interrupts/
	__disable_irq();

	//Enable clock access for GPIOC/
	RCC->AHB1ENR |=GPIOCEN;

	//Set PC13 as input/
	GPIOC->MODER &=~(1U<<26);
	GPIOC->MODER &=~(1U<<27);


	//Enable clock access to SYSCFG/
	RCC->APB2ENR |=SYSCFGEN;

	//Select PORTC for EXTI13/
	SYSCFG->EXTICR[3] |=(1U<<5);

	//Unmask EXTI13/
	EXTI->IMR |=(1U<<13);

	//Select falling edge trigger/
	EXTI->FTSR |=(1U<<13);

	//Enable EXTI13 line in NVIC/
	NVIC_EnableIRQ(EXTI15_10_IRQn);

	//Enable global interrupts/
	__enable_irq();


}
