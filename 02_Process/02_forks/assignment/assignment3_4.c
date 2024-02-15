/*
*  A tricky example, fork() is called multiple times
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
   //fork() && fork();
   fork() || fork();
   //fprintf(stderr, "%s","PHYTEC");
   printf("PHYTEC\n");
   return 0;
}


/*  
if (fork()){
  fork();
}


if (!fork()){
  fork();
}

*/
