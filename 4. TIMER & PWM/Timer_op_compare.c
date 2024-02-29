#include "stm32f4xx.h"



#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1E	(1U<<0)


#define GPIOAEN		(1U<<0)
#define AFR5_TIM	(1U<<20)

void tim2_pa5_output_compare(void)
{

	 /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;

	/*Set PA5 mode to alternate function*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |=(1U<<11);

	/*Set PA5 alternate function type to TIM2_CH1 (AF01)*/
	GPIOA->AFR[0] |=AFR5_TIM;

	/*Enable clock access to tim2*/
	RCC->APB1ENR |=TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1

	/*Set output compare toggle mode ccmr1*/
	TIM2->CCMR1 = 0;
	TIM2->CCMR1 |=0x0020;
	/*Enable tim2 ch1 in compare mode ccer*/
	TIM2->CCER = CCER_CC1E;

	/*Clear counter*/
	TIM2->CNT = 0;
	/*Enable timer*/
	TIM2->CR1 = CR1_CEN;
}
int main()
{
	tim2_pa5_output_compare();
	//while(1){}
}
