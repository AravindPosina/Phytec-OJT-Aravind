# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int pid1, pid2, pid3;
	if((pid1 = fork()) == 0){
		printf("PID is :%d\n",getpid());
		sleep(2);}
	else if((pid2 = fork()) == 0){
		printf("PID is :%d\n",getpid());
		sleep(2);}
	else if((pid3 = fork()) == 0){
		printf("PID is :%d\n",getpid());
		sleep(2);}
	else{
		printf("PID is :%d\n",getpid());
		waitpid(pid1,0,0);
		waitpid(pid2,0,0);
		waitpid(pid3,0,0);
	}
}
