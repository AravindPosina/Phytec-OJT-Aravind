#include "stm32f4xx.h"
#define SLAVE_ADDR 0x68 /* 1101 000. DS1337 */
void delayMs(int n);
void I2C1_init(void);
int I2C1_byteRead(char saddr, char maddr, char* data);
int I2C1_byteWrite(char saddr, char maddr, char data);

int main(void)
{
char data;
I2C1_init();
//I2C1_byteWrite(saddr,maddr,data);
/* configure PA5 for the green LED (LD2) */
RCC->AHB1ENR |=(1U<<0);
/* enable GPIOA clock */
GPIOA->MODER |=(1U<<10);
/* clear pin mode */
/*A->MODER |= */
/* set pin to output mode */
I2C1_byteRead(SLAVE_ADDR, 0, &data);
while (1)
{
I2C1_byteRead(SLAVE_ADDR, 0, &data);
if (data & 1)
GPIOA->ODR |= (1U<<5); /* turn on LED */
else
GPIOA->ODR &= ~(1U<<5); /* turn off LED */
delayMs(10); }
}

void I2C1_init(void)
{

RCC->AHB1ENR |= (1U<<1); /* Enable GPIOB clock */
RCC->APB1ENR |=(1U<<21); /* Enable I2C1 clock */
/* configure PB8, PB9 pins for I2C1 */
GPIOB->AFR[1] |= (4U<<0);
/* PB8, PB9 I2C1 SCL, SDA */
GPIOB->AFR[1] |= (4U<<4);
GPIOB->MODER |= (2U<<16); /* PB8, PB9 use alternate function */
GPIOB->MODER |= (2U<<18);
GPIOB->OTYPER |=(1U<<8);/* output open-drain */
GPIOB->OTYPER |=(1U<<9);/* output open-drain */
GPIOB->PUPDR |=(1U<<16); /* with pull-ups */
GPIOB->PUPDR |=(1U<<18);
I2C1->CR1 |=(1U<<15); /* software reset I2C1 */
I2C1->CR1 &= ~(1U<<15); /* out of reset */
I2C1->CR2 = (1U<<4); /* peripheral clock is 16 MHz*/
I2C1->CCR = 80; /* standard mode, 100kHz clock */
I2C1->TRISE =17; /* maximum rise time */
I2C1->CR1 |= (1U<<0); /* enable I2C1module */
}
int I2C1_byteRead(char saddr, char maddr, char* data)
{
volatile int tmp;
while (I2C1->SR2 & 2); /* wait until bus not busy */
I2C1->CR1 |= 0x100; /* generate start */
while (!(I2C1->SR1 & 1));/* wait until start flag is set */
I2C1->DR = saddr << 1; /* transmit slave address + Write */
while (!(I2C1->SR1 & 2)); /* wait until addr flag is set */
tmp = I2C1->SR2;/* clear addr flag */
while (!(I2C1->SR1 & 0x80)); /* wait until data register empty */
I2C1->DR = maddr; /* send memory address */
while (!(I2C1->SR1 & 0x80)); /* wait until data register empty */
I2C1->CR1 |= 0x100; /* generate restart */
while (!(I2C1->SR1 & 1));/* wait until start flag is set */
I2C1->DR = saddr << 1 | 1; /*transmit slave address + Read */
while (!(I2C1->SR1 & 2)); /* wait until addr flag is set */
I2C1->CR1 &= ~0x400; /* Disable Acknowledge */
tmp = I2C1->SR2; /* clearaddr flag */
I2C1->CR1 |= 0x200; /* generate stop after data received */
while (!(I2C1->SR1 & 0x40)); /* Wait until RXNE flag is set */
data++ = I2C1->DR; /* Read data from DR */
return 0;
}/* 16 MHz SYSCLK */
void delayMs(int n)
{
int i;
for (; n > 0; n--)
for (i = 0; i < 3195; i++) ;
}


int I2C1_byteWrite(char saddr, char maddr, char data)
{
volatile int tmp;
while (I2C1->SR2 & 2); /* wait until bus not busy */
I2C1->CR1 |= 0x100; /* generate start */
while (!(I2C1->SR1 & 1));/* wait until start flag is set */
I2C1->DR = saddr << 1; /* transmit slave address */
while (!(I2C1->SR1 & 2)); /* wait until addr flag is set */
tmp = I2C1->SR2; /*clear addr flag */
while (!(I2C1->SR1 & 0x80)); /* wait until data register empty */
I2C1->DR = maddr; /* send memory address */
while (!(I2C1->SR1 & 0x80)); /* wait until data register empty */
I2C1->DR = data; /* transmit data */
while (!(I2C1->SR1 & 4)); /* wait until transfer finished */
I2C1->CR1 |= 0x200; /* generate stop */
return 0;
}
