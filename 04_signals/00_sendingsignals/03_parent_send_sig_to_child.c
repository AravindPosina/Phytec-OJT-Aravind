/*
*  Parent process sends a signal to child process using kill()
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   pid_t cpid = fork();
      

   if (cpid ==0)
   {
      for(;;)
      {
      	  printf("in child cpid=%d \n",cpid);
         printf("I am child in an infinite loop\n");
         sleep(1);
      }
   }
   else
   {
      sleep(5);
      kill(cpid,SIGINT); 
      printf("Oh! I have killed my child...\n");
   }
return 0;
}

