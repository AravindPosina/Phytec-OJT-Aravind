#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>	
#include<stdio.h>
#include<string.h>  
#include<stdlib.h>

#define GPIO_EN  "/sys/class/gpio/export"
#define GPIO_DIR "/sys/class/gpio/PD19/direction"
#define GPIO_Val "/sys/class/gpio/PD19/value"

int main()
{
	// PD19-----> Pin 12 on exp header of RB-A5d2x
	
	int  gpio_fd;
	char gpio_buf[30];
	int  gpio_num = 115;
	int  count =10;
	gpio_fd = open(GPIO_EN,O_WRONLY);
	if(gpio_fd < 0)
	{
		printf("Unable to open the file  %s\n",GPIO_EN);
		exit(0);
	}
	printf("Enable the GPIO");
	sprintf(gpio_buf,"%d",gpio_num);
	write(gpio_fd,gpio_buf,strlen(gpio_buf));
	close(gpio_fd);

	printf("Configuring GPIO direction  \n");

	gpio_fd = open(GPIO_DIR,O_WRONLY);
	if(gpio_fd < 0)
	{
		printf("Unable to open the file   %s",GPIO_DIR);
		exit(0);
	}

	write(gpio_fd,"out",3);
	close(gpio_fd);

	printf("Set the value into GPIO_Val \n");
	printf("Toggling the GPIO_PIN");
	gpio_fd = open( GPIO_Val,O_WRONLY);
	if(gpio_fd < 0)
	{
		printf("Unable to open the file   %s",GPIO_Val);
		exit(0);
	}
	
	while(count--)
	{
		write(gpio_fd,"1" ,1);
		sleep(1);
		write(gpio_fd,"0" ,1);
		sleep(1);
	}
	
	close(gpio_fd);
	
}
