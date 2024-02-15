#include"signal.h"
#include"stdio.h"
#include"unistd.h"

void sig_handler1(int sig)
{
	printf("I am inside signal handler1\n");
	wait(NULL);

}

int main()
{
	int pid;
	pid=fork();
	printf("The process id is %d\n",getpid());
	if(pid==-1)
	{
		printf("error no signal created\n");

	}
	if(pid==0)
	{
		printf("sucessfully created child and my pid is %d\n",getpid());

	}
	else
	{
		printf("I am in parent process\n");
		(void)signal(SIGCHLD,sig_handler1);

	while(1)
	{
		printf("I am in parent process\n");
		sleep(2);
	}
	return 0;

	}

}
