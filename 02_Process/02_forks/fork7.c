/*
*  Describes what happens when fork() is called multiple times
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if(argc!=2){
      printf("Must enter one agrument (an integer)\n");
      exit(1);
   }
   int n = atoi(argv[1]);
   int i;
   for (i=1;i<=n;i++)
      fork();
   printf("PHYTEC\n");
   exit(0);
}
