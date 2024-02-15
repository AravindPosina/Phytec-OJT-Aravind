/***************************************************************
                                 wait.c  -  description
                                    -------------------
           begin                : Wed Jul 23 2003
****************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int chpid1,chpid2;
	if((chpid1 =fork())== 0){//Child starts here
		printf(" Child pid = %d\n",getpid());
		sleep(2);
		printf("First child exited\n");
	}
	else {//Parent's segment
		printf(" pid of parent = %d\n",getpid());
		if((chpid2 = fork())== 0){//second childs block
			printf("pid of second child is %d\n",getpid());
			sleep(5);
			printf("The second child exited\n");
		}
		else {//Parents block
			printf("Before waitpid())\n");

			waitpid(chpid1,NULL,0);//wait for child1's exit status 
			waitpid(chpid2,NULL,0);//wait for second child's exit status

			printf("pid of parent is : %d\n",getpid());
		}
	}
}
						
