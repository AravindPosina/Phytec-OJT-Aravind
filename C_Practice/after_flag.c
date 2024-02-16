#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{

	int n;
	char buff;
	int fd =open("adc.txt",O_RDONLY);
	printf("%d\n",fd);
	write(1,buff,n);
	int flags=fcntl(fd,F_GETFL,0);
	flags=flags|O_APPEND;
	fcntl(fd,F_SETFL,flags);
	close(0);
	fd =open("adc.txt",O_RDONLY);
	printf("%d\n",fd);
	return 0;
}
