#include "stm32f4xx.h"

	void UART2_init(void);
	void UART2_write(int c);
	void delayMs(int);
	char UART2_read(void);

	int main (void)
	{
		char c;
		UART2_init();
			while (1)
			{
				c = UART2_read();
				UART2_write(c);
			}
	}
	/* initialize UART4 to transmit at 9600 Baud */
	void UART2_init(void)
	{
		RCC->AHB1ENR |= 1; /* Enable GPIOA clock */
		RCC->APB1ENR |= 0x0020000; /* Enable UART2 clock */
		/* Configure PA0, PA1 for UART4 TX, RX */
		GPIOA->AFR[0] =0;
		GPIOA->AFR[0] |= 0x00000770; /* alt8 for UART4 */
		GPIOA->MODER =0;
		GPIOA->MODER |= 0x000000C0; /* enable alternate function for PA0, PA1 */
		USART2->BRR = 0x0683; /* 9600 baud @ 16 MHz */
		USART2->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
		USART2->CR2 = 0x0000; /* 1 stop bit*/
		USART2->CR3 = 0x0000; /* no flow control */
		USART2->CR1 |= 0x2000; /*enable UART4 */
	}
	/* Write a character to UART4 */

		void UART2_write(int ch) {
		while(!(USART2->SR & 0x0080)) {} // wait until Tx buffer empty
		USART2->DR = (ch & 0xFF);
	}
	/* Read a character from UART4 */
		char UART2_read(void) {
		while (!(USART2->SR & 0x0020)) {} // wait until char arrives
		return USART2->DR;
}

