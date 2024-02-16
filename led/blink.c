#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int fd = open("/sys/class/gpio/export",O_WRONLY);
	write(fd,77,1000);
	close(fd);
	
	fd = open("/sys/class/gpio/PC13/direction",O_WRONLY);
	write(fd,"out",1000);
	close(fd);
	
	fd = open("/sys/class/gpio/PC13/value",O_WRONLY);
	write(fd,1,1000);
	delay();
	write(fd,0,1000);
	delay();
	write(fd,1,1000);
	delay();
	write(fd,0,1000);
	delay();
	close(fd);

}

void delay()
{
	for(int i=0;i<100000;i++)
		for(int j=0;j<i;j++);
}
