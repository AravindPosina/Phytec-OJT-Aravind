#include<stdio.h>
#include <unistd.h>
#include<signal.h>
void sig_handler(int signum){
  printf("Inside handler function\n");
}

int main(){
  pid_t pid;
  signal(SIGUSR1,sig_handler); // Register signal handler
  printf("Inside main function\n");
  pid=getpid();      //Process ID of itself
  kill(pid,SIGUSR1);        // Send SIGUSR1 to itself
  printf("Inside main function\n");
  return 0;
}
