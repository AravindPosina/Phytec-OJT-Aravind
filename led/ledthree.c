#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int fd = open("/sys/class/gpio/export",O_WRONLY);
	write(fd,"77",10);
	close(fd);
	
	int fd1 = open("/sys/class/gpio/export",O_WRONLY);
	write(fd1,"81",10);
	close(fd1);
	
	int fd2 = open("/sys/class/gpio/export",O_WRONLY);
	write(fd2,"83",10);
	close(fd2);
	
	fd = open("/sys/class/gpio/PC13/direction",O_WRONLY);
	write(fd,"out",10);
	close(fd);
	
	fd1 = open("/sys/class/gpio/PC17/direction",O_WRONLY);
	write(fd1,"out",10);
	close(fd1);
	
	fd2 = open("/sys/class/gpio/PC19/direction",O_WRONLY);
	write(fd2,"out",10);
	close(fd2);
	
	fd = open("/sys/class/gpio/PC13/value",O_WRONLY);
	fd1 = open("/sys/class/gpio/PC17/value",O_WRONLY);
	fd2 = open("/sys/class/gpio/PC19/value",O_WRONLY);	
	while(1)
	{
		write(fd,"1",10);
		delay();
		write(fd,"0",10);
		delay();
		
		write(fd1,"1",10);
		delay();
		write(fd1,"0",10);
		delay();
		
		write(fd2,"1",10);
		delay();
		write(fd2,"0",10);
		delay();
	}
	close(fd);
	close(fd1);
	close(fd2);
}

void delay()
{
	for(int i=0;i<100+00;i++)
		for(int j=0;j<i;j++);
}
