#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buff[100];
	int fd=open("etc/passwd",O_RDONLY);
	printf("the fd is %d\n",fd);
        int n=read(STDIN,buff,255);
        write(STDOUT_FILENO,buff,n);
	int rv=fcntl(fd,F_DUPFD,54);
	printf("duplicate is %d\n",rv);
	return 0;
}
