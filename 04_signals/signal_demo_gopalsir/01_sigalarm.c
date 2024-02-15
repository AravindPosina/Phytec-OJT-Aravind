#include"signal.h"
#include"stdio.h"
#include"unistd.h"

void fun(int sig)
{
	printf("wake up alarm \n");
	alarm(2);

}

int main()
{
	int pid;

	//(void)signal(SIGALRM,fun);
	printf("The process id is %d\n",getpid());
	(void)signal(SIGALRM,fun);
	alarm(5);
		//printf("hello world\n");
		//sleep(1);
	while(1);
	return 0;

}
