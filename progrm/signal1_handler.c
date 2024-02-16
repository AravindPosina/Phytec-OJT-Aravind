#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void myhandler(int signum)
{
 printf("hey,i got signal:%d\n",signum);
 for (int i=1;i<=10;i++)
 {
        printf("i am masking SIGINT for 10 second\n");
	sleep(1);
        struct sigaction newact;
        newact.sa_handler=SIG_DFL;
        newact.sa_flags=0;
        sigemptyset(&newact.sa_mask);
        sigaction(SIGINT,&newact,NULL);
	sleep(1);

}

 printf("done with the handler function and falling back to main() after2 secs\n\n");
 sleep(3);
}
int main()
{
        struct sigaction newact;
        newact.sa_handler=myhandler;
        newact.sa_flags=0;
        sigemptyset(&newact.sa_mask);
        sigaction(SIGINT,&newact,NULL);
        while(1)
        {
                printf("i am main() in an infinite loop!\n");
                sleep(1);
        }
        return 0;
}


