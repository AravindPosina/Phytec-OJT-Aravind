#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int signum)
{
	printf("\nhey,i got SIGINT: %d\n\n",signum);
	signal(SIGINT,SIG_DFL);
}
void sigquit_handler(int signum)
{
	printf("\n hey, i got SIGQUIT:%d \n\n",signum);
	signal(SIGQUIT,SIG_DFL);
}
void sigkill_handler(int signum)
{
	printf("\n hey, i got SIGKILL:%d\n\n",signum);
	signal(SIGKILL,SIG_DFL);
}

void sigstop_handler(int signum)
{
	printf("\n hey, i got SIGSTOP:%d\n\n",signum);
	signal(SIGSTOP,SIG_DFL);
}


void sigtstp_handler(int signum)

{
	printf("\n hey, i got SIGSTSTP:%d\n\n",signum);
	signal(SIGTSTP,SIG_DFL);
}

void sigfpe_handler(int signum)
{
	printf("\n hey, i got SIGFPE:%d\n\n",signum);
	signal(SIGFPE,SIG_DFL);
}
int main()
{

	signal(SIGINT,sigint_handler);
	signal(SIGTSTP,sigtstp_handler);
	signal(SIGFPE,sigfpe_handler);
	signal(SIGKILL,sigkill_handler);
	signal(SIGQUIT,sigquit_handler);
	signal(SIGSTOP,sigstop_handler);
	while(1)
	{
		printf("i am in the infinite loop!\n");
		sleep(1);
	}
	return 0;
		
}
