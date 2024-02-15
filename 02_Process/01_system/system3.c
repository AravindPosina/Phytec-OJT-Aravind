/*
*  A shell interpreter using system()
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
   char cmd[50];
   int cpid;
   do{
      printf("PHYTEC:- ");
      fgets(cmd, 50,stdin);
      system(cmd);
   }while(1);
   return 0;
}
