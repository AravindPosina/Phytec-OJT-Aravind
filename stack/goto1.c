#include <stdio.h>

int main(){
   printf("Start of loop.\n");
   int ctr=1;
   label1: 
   printf ("PHYTEC\n");
   ctr++;
   if (ctr == 6)
      goto label2;
   goto label1;
   label2:
   printf("Out of loop\n");
   return 0;
}
