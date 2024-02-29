#include "stm32f4xx.h"
void UART4_init(void);
void UART4_write(int ch);
void delayMs(int);
char UART4_read(void);
void write(int ch);
void writ(int c);

int count=0;
int count1=0;
int main (void) {
char c;


UART4_init();
while(1)
{
for(int i=0;i<12;i++)
	void UART4_init(void);
	void UART4_write(int ch);
	void delayMs(int);
	char UART4_read(void);
	void write(int ch);
	void writ(int c);

	int count=0;
	int count1=0;
	int main (void) {
	char c;


	UART4_init();
	while(1)
	{
	for(int i=0;i<12;i++)
	{

	c=UART4_read();
	writ(c);
	UART4_write(c);

}

if(count==22)
{
	//write('\r');

	char b[50]="-shivani";
	for(int i=0;b[i]!='\0';i++)
	{
		write(b[i]);

	}
	count-=count;
	count1-=count1;
	write('\r');
	write('\n');

}
else if(count1==22)
{

	//write('\r');

	char g[50]="-vijaylakshmi";
	for(int i=0;g[i]!='\0';i++)
	{
		write(g[i]);

	}
	count1-=count1;
	count-=count;
	write('\r');
	write('\n');
}
else
{


	char l[50]="-sasi";
		for(int i=0;l[i]!='\0';i++)
		{
			write(l[i]);

		}
		count-=count;
		count1-=count1;
		write('\r');
		write('\n');
}
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
    char arr1[2][20] = {"1800890BBg23", "180088FFBCD3"};

    while (!(UART4->SR & 0x0080)) {} // wait until Tx buffer empty


    /*for(int j=0;j<2;j++)
    {*/
    for (int i=0; i<12; i++) {
        if (ch == arr1[0][i]) // Compare the first character of arr1[i]
        	count++;
    }
    for(int j=0;j<12;j++)
    {
    	if(ch==arr1[1][j])
    		count1++;
    }
    }


//}

char UART4_read(void) {
while (!(UART4->SR & 0x0020)) {}
// wait until char arrives
return UART4->DR;
}


void write(int ch)
{
	while (!(UART4->SR & 0x0080)) {}

	UART4->DR = ch & 0xff;
}


void writ(int c)
{
	while (!(UART4->SR & 0x0080)) {}

	UART4->DR = c & 0xff;
}
