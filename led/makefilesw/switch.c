#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
int fd = open("/sys/class/gpio/export",O_WRONLY);
write(fd,"77",10);
close(fd);

fd = open("/sys/class/gpio/export",O_WRONLY);
write(fd,"81",10);
close(fd);

fd = open("/sys/class/gpio/export",O_WRONLY);
write(fd,"83",10);
close(fd);

fd = open("/sys/class/gpio/export",O_WRONLY);
write(fd,"76",10);
close(fd);


fd = open("/sys/class/gpio/PC13/direction",O_WRONLY);
write(fd,"out",10);
close(fd);

fd = open("/sys/class/gpio/PC17/direction",O_WRONLY);
write(fd,"out",10);
close(fd);

fd = open("/sys/class/gpio/PC19/direction",O_WRONLY);
write(fd,"out",10);
close(fd);

fd = open("/sys/class/gpio/PC12/direction",O_WRONLY);
write(fd,"in",10);
close(fd);


int fd1 = open("/sys/class/gpio/PC13/value",O_WRONLY);
int fd2 = open("/sys/class/gpio/PC17/value",O_WRONLY);
int fd3 = open("/sys/class/gpio/PC19/value",O_WRONLY);
while(1)
{
char buff;

fd = open("/sys/class/gpio/PC12/value",O_RDONLY);
read(fd,&buff,1);
close(fd);

if(buff == '1')
{
write(fd1,"1",1);
write(fd2,"1",1);
write(fd3,"1",1);
delay(500);
}
else
{
write(fd1,"0",1);
write(fd2,"0",1);
write(fd3,"0",1);
delay(500);
}
}
close(fd1);
close(fd2);
close(fd3);
return 0;


}

void delay(int n)
{
    int i;
    for (; n > 0; n--)
        for (i = 0; i < 3195; i++);
}
