#include"signal.h"
#include"stdio.h"
#include"unistd.h"

void sig_handler1(int sig)
{
	printf("I am inside signal handler1\n");

}

void sig_handler2(int sig)
{
	printf("I am inside signal handler2 \n");

}
int main()
{
	int pid;
	printf("The process id is %d\n",getpid());
	(void)signal(SIGHUP,sig_handler1);
	
	(void)signal(SIGKILL,sig_handler2);

	while(1)
	{
		(void)signal(SIGHUP,sig_handler1);
		(void)signal(SIGKILL,sig_handler2);
		printf("hello world\n");
		sleep(2);
	}
	return 0;

}
