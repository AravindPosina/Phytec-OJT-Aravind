#include "LiquidCrystal_PCF8574.h"
#include "stdint.h"


#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* mraa header */
#include "mraa/i2c.h"
#define SLAVE_ADDRESS_LCD (0x27) // change this according to ur setup

#define I2C_BUS 1

mraa_result_t status = MRAA_SUCCESS;
mraa_i2c_context i2c;


int i2c_init(void)
{
	i2c = mraa_i2c_init(I2C_BUS);
	if (i2c == NULL) {
        	fprintf(stderr, "Failed to initialize I2C\n");
        	mraa_deinit();
        	return EXIT_FAILURE;
    	}	
    
    
	/* set slave address */
    	status = mraa_i2c_address(i2c, SLAVE_ADDRESS_LCD);
    	if (status != MRAA_SUCCESS) {
        	return EXIT_FAILURE;
    	}
 }  
    
    
    
    
void lcd_write_i2c(mraa_i2c_context i2c,uint8_t *buffer, int length)
{
		status = mraa_i2c_write(i2c, buffer, length);
    		if (status != MRAA_SUCCESS) {
        		exit(1);
    		}		

}


void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	lcd_write_i2c(i2c,(uint8_t *)data_t,4);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=1
	data_t[1] = data_u|0x09;  //en=0, rs=1
	data_t[2] = data_l|0x0D;  //en=1, rs=1
	data_t[3] = data_l|0x09;  //en=0, rs=1
	lcd_write_i2c(i2c,(uint8_t *)data_t,4);
}

void setCursor(int a, int b)
{
	int i=0;
	switch(b){
	case 0:lcd_send_cmd(0x80);break;
	case 1:lcd_send_cmd(0xC0);break;
	case 2:lcd_send_cmd(0x94);break;
	case 3:lcd_send_cmd(0xd4);break;}
	for(i=0;i<a;i++)
	lcd_send_cmd(0x14);
}


void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}
void lcd_init (void)
{
	i2c_init();
	// 4 bit initialisation
	usleep(50000);  // wait for >40ms
	lcd_send_cmd (0x3);
	usleep(5000);  // wait for >4.1ms
	lcd_send_cmd (0x3);
	usleep(110);  // wait for >100us
	lcd_send_cmd (0x3);
	usleep(10000);
	lcd_send_cmd (0x2);  // 4bit mode
	usleep(10000);

  // dislay initialisation
	lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	usleep(1000);
	lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	usleep(1000);
	lcd_send_cmd (0x01);  // clear display
	usleep(1000);
	usleep(1000);
	lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	usleep(1000);
	lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}

void lcd_clear (void)
{

	#define LCD_CLEARDISPLAY 0x01
	lcd_send_cmd(LCD_CLEARDISPLAY);
	usleep(100000);
	
}
