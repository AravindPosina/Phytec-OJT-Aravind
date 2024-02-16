#include<stdio.h>
void main() {
    printf("welcome to main\n");
    delhi();
    mumbai();
    chennai();
    printf("we are finally in main\n");
   }
  void mumbai()
  {
     printf("we are in mumbai\n");
     chennai();
  }
  void chennai()
  {
    delhi();
    printf("we are in chennai\n");
   }
  void delhi()
  {
   
    printf("we are in delhi\n");

   }

