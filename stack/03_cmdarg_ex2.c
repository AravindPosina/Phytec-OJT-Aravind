#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
   if (strcmp(argv[0], "./hello")==0)
      printf("I am called by the name hello\n");
   else if (strcmp(argv[0], "./bye")==0)
      printf("I am called by the name bye\n");
   else
      printf("I am called by the name a.out\n");
   return 0;

}
