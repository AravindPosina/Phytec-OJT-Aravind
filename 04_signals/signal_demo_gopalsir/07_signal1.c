#include"signal.h"
#include"stdio.h"
#include"unistd.h"

void fun(int sig)
{
	printf("I get signal %d\n",sig);

}

int main()
{
	int pid;

	(void)signal(SIGINT,fun);
	//(void)signal(SIGTERM,fun);
	printf("The process id is %d\n",getpid());
	while(1)
	{
		(void)signal(SIGTERM,fun);
		printf("hello world\n");
		sleep(1);
	}
	return 0;

}
