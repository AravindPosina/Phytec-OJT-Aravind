/*
*  Proof of concept: Exit handlers are not inherited after exec()
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
void exit_handler(){
   printf("Exit handler\n");
}
int main(){
   atexit(exit_handler);

pid_t cpid = fork();
   if (cpid == 0){
      //execlp("ls","name","-l", "/home/", NULL);
      execlp("ls","myls","/home", NULL);
      printf("This is child process.\n");
      exit(0);
   }
   else{
      wait(NULL);
      printf("This is parent process.\n");
      exit(0);
   }
}
