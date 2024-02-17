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
	int  gpio_fd,fd;
	char gpio_buf[30];
	int  gpio_num = 77;
	char  value;
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

	fd = open("/sys/class/gpio/export",O_WRONLY);
	 if(fd < 0)
        {
                printf("Unable to export the file PC12   \n");
                exit(0);
        }
        write(fd,"76",3);
        close(fd);

        fd =open("/sys/class/gpio/PC12/direction",O_WRONLY);
	if(fd < 0)
        {
                printf("Unable to open the file direction  \n");
                exit(0);
        }
        write(fd,"in",3);
        close(fd);


	while(10)
	{
	        fd = open("/sys/class/gpio/PC12/value",O_RDONLY);
		if(fd < 0)
        	{	
                	printf("Unable to open the file   \n");
                	exit(0);
        	}
	        read(fd,&value,1);
		if(value=='0')
			write(gpio_fd,"0" ,1);
		else
			write(gpio_fd,"1" ,1);
		close(fd);
	}
	close(gpio_fd);
}
