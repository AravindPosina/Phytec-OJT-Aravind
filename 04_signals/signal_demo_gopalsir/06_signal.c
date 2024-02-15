#include"signal.h"
#include"stdio.h"
#include"unistd.h"

void fun(int sig)
{
	printf("I get signal %d\n",sig);

}

int main()
{
	(void)signal(SIGINT,fun);
	while(1)
	{
		(void)signal(SIGINT,SIG_IGN);
		printf("hello world\n");
		sleep(1);
	}
	return 0;

}
