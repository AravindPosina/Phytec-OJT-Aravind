#include "stm32f4xx.h"

	void UART4_init(void);
	void UART4_write(int c);
	void delayMs(int);
	char UART4_read(void);

	int main (void)
	{
		char c;
		UART4_init();
			while (1)
			{
				c = UART4_read();
				UART4_write(c);
			}
	}
	/* initialize UART4 to transmit at 9600 Baud */
	void UART4_init(void)
	{
		RCC->AHB1ENR |= 1; /* Enable GPIOA clock */
		RCC->APB1ENR |= 0x80000; /* Enable UART4 clock */
		/* Configure PA0, PA1 for UART4 TX, RX */
		GPIOA->AFR[0] &= ~0x00FF;
		GPIOA->AFR[0] |= 0x0088; /* alt8 for UART4 */
		GPIOA->MODER &= ~0x000F;
		GPIOA->MODER |= 0x000A; /* enable alternate function for PA0, PA1 */
		UART4->BRR = 0x0683; /* 9600 baud @ 16 MHz */
		UART4->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
		UART4->CR2 = 0x0000; /* 1 stop bit*/
		UART4->CR3 = 0x0000; /* no flow control */
		UART4->CR1 |= 0x2000; /*enable UART4 */
	}
	/* Write a character to UART4 */

		void UART4_write(int ch) {
		while (!(UART4->SR & 0x0080)) {} // wait until Tx buffer empty
		UART4->DR = (ch & 0xFF);
	}
	/* Read a character from UART4 */
		char UART4_read(void) {
		while (!(UART4->SR & 0x0020)) {} // wait until char arrives
		return UART4->DR;
}
