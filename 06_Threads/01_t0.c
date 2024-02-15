/*
*  t0.c: main function calls two functions f1() and f2()
*  f1() prints string PHYTEC five times with a delay of 1 sec
*  f2() prints string RB five times with a delay of 1 sec
*  compile: $ gcc t0.c 
*  usage: $time ./a.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void f1();
void f2();
int main(){
   f1();
   f2();
   printf("\nBye Bye from main\n");   
   return 0;
}

void f1(){
   for(int i=0; i<5; i++){
      printf("%s", "PHYTEC");
      fflush(stdout);
      sleep(1);
   }
}
void f2(){
   for(int i=0; i<5; i++){
      printf("%s", "RB");
      fflush(stdout);
      sleep(1);
   }
}
