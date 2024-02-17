/*********************************************************************************************
 * © 2022 PHYTEC EMBEDDED PVT LTD. - All Rights Reserved. Permission to use, modify, copy, and distribute
 * this source code, object code, or executable code (collectively, Software), is granted only
 * under the terms of a valid written license agreement with PHYTEC. Unauthorized copying
 * or other use of the Software is strictly prohibited.  Software is owned by and constitutes
 * the proprietary works, trade secrets, and copyrights of Embitel or its licensors.
 *
 * For further information, contact PHYTEC EMBEDDED Pvt Ltd.
 *********************************************************************************************/
/*********************************************************************************************/
/*      Application: Led_Blink_GPIO.c
 *
 *      Brief: This application is to blink user Led connected to PC13 
 *
 *      Author: PHYTEC EMBEDDED PVT LTD
 */
/*********************************************************************************************/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>	
#include<stdio.h>
#include<string.h>  
#include<stdlib.h>

#define GPIO_EN  "/sys/class/gpio/export"
#define GPIO_DIR "/sys/class/gpio/PC13/direction"
#define GPIO_Val "/sys/class/gpio/PC13/value"

int main()
{
	int  gpio_fd;
	char gpio_buf[30];
	int  gpio_num = 77;
	int  count =10;
	gpio_fd = open(GPIO_EN,O_WRONLY);
	if(gpio_fd < 0)
	{
		printf("Unable to open the file  %s\n",GPIO_EN);
		exit(0);
	}
//	printf("Enable the GPIO");
	sprintf(gpio_buf,"%d",gpio_num);
	write(gpio_fd,gpio_buf,strlen(gpio_buf));
	close(gpio_fd);

//	printf("Configuring GPIO direction  \n");

	gpio_fd = open(GPIO_DIR,O_WRONLY);
	if(gpio_fd < 0)
	{
		printf("Unable to open the file   %s",GPIO_DIR);
		exit(0);
	}

	write(gpio_fd,"out",3);
	close(gpio_fd);

//	printf("Set the value into GPIO_Val \n");

	gpio_fd = open( GPIO_Val,O_WRONLY);
	if(gpio_fd < 0)
	{
		printf("Unable to open the file   %s",GPIO_Val);
		exit(0);
	}
	printf("Toggling the GPIO_PIN\n");
	while(count--)
	{
		write(gpio_fd,"0" ,1);
		sleep(2);
		write(gpio_fd,"1" ,1);
		sleep(2);
	}
	close(gpio_fd);
}
