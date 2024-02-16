#include<stdio.h>
#include<string.h>

int main() {
   // Write C code here
   char s1[30];
   printf("Enter the string: ");
   scanf("%s", s1);
   
   for(int i = 0; s1[i] != '\0'; i++) {
      if(s1[i] >= 'a' && s1[i] <= 'z') {
         s1[i] = s1[i] - 32;
      }
   }

   printf("The upper case is %s", s1);

   return 0;
}

