#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;
int main(){
   char * arr  = (char*) malloc (sizeof(char)*10);
   if(arr==NULL){
      perror("malloc failed:");
      exit(errno);
   }
   arr[0]='P';
   arr[1]='H';
   arr[2]='Y';
   arr[3]='T';
   arr[4]='E';
   arr[5]='C';
   arr[6]='\0';
   printf("%s\n",arr);
   free(arr);
   arr[0] = 'b';
   return 0;
}
