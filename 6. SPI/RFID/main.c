/*SPI CONNECTION:
 *
 * MOSI----->PA7
 * MISO----->PA6
 * RST------>PA8
 * SCK------>PA5
 * SDA/CS------>PB0
 * VCC--------->3.3V
 *
 *
 ***************************
 * I2C_LCD CONNECTION:
 *
 * SDA-------->PB9
 * SCL-------->PB8
 * VCC-------->5V
 *
 ***************************
 *
 */


#include "LiquidCrystal_PCF8574.h"
#include "delay.h"
#include "stdio.h"
#include "RFID.h"
#include "stm32f4xx_hal.h" // Include STM32F4 HAL library
#include "string.h"
extern void SysClockConfig(void);

UART_HandleTypeDef huart2; // UART handler

uint8_t rfid_id[4];

int main(void)
{
    // Initialize the HAL library
    HAL_Init();

    // Initialize the system clock
 //   SysClockConfig();

    // Initialize the UART peripheral
    __HAL_RCC_USART2_CLK_ENABLE(); // Enable UART2 clock
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 9600;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart2);

    // Initialize RFID and LCD
    systick_init_ms(16000000);
    rc522_init();
    lcd_init();

    // Display initial message on LCD
    setCursor(0, 0);
    lcd_send_string("TESTING RFID!");
    setCursor(3, 1);
    lcd_send_string("with STM32F4");

    while(1)
    {
        if(rc522_checkCard(rfid_id))
        {
            // RFID card detected
            lcd_clear();
            char data[20];
            setCursor(0, 0);
            lcd_send_string("RFID code is");
            setCursor(0, 1);
            sprintf(data, "0x%x 0x%x 0x%x 0x%x", rfid_id[0], rfid_id[1], rfid_id[2], rfid_id[3]);
            lcd_send_string(data);

            // Send RFID data over UART
            HAL_UART_Transmit(&huart2, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);

            delay(1000);
        }
        delay(100);
    }
}
