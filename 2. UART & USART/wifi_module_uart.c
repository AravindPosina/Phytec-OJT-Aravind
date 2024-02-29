#include"stm32f4xx.h"

	void usart1_init(void);
	void UART1_write(int ch);
	char usart1_read(void);

		void delayMs(int n)
		{
		   int i;
		   for (; n > 0; n--)
		   for (i = 0; i < 3195; i++);
}

		int main(void)
		{
			usart1_init();
			char message[] = "CMD+RESET\r\n";
			int i;
			for (i = 0; message[i] != '\0'; i++) {
				USART1_write(message[i]);
			}
			delayMs(1000);
			char messag[] = "CMD+WIFIMODE=1\r\n";
			int j;
			for (j = 0; messag[j] != '\0'; j++) {
				USART1_write(messag[j]);
			}
			delayMs(1000);
			char msg[] = "CMD+CONTOAP=vivo 1917,11111111	\r\n";
			int k;
			for (k = 0; msg[k] != '\0'; k++) {
			USART1_write(msg[k]);
	}


}




void usart1_init(void)
{
	RCC->AHB1ENR |= 1;
	RCC->APB2ENR |= 0x00000010;
	GPIOA->MODER &= ~0x003C0000;
	GPIOA->MODER |= 0x00280000;
	GPIOA->AFR[1] &= ~0x0FF0;
	GPIOA->AFR[1] |= 0x0770 ; /* alt8 for UART1 */
	USART1->BRR = 0x01A1; /* 9600 baud @ 16 MHz */
	USART1->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
	USART1->CR2 = 0x0000; /* 1 stop bit*/
	USART1->CR3 = 0x0000; /* no flow control */
	USART1->CR1 |= 0x2000; /*enable UART1 */

}



void USART1_write(int ch) {
while (!(USART1->SR & 0x0080)) {} // wait until Tx buffer empty
USART1->DR = (ch & 0xFF);
}
/* Read a character from UART4 */
char usart1_read(void) {
while (!(USART1->SR & 0x0020)) {} // wait until char arrives
return USART1->DR;
}
