#include<stdio.h>
#include<string.h>

int main() {
    // Write C code here
   char s1[30];
   printf("enter the string: ");
   scanf("%s",s1);

   for(int i=0;s1[i] !='\0';i++)
	  {
		  if(s1[i]>='A' && s1[i]<='Z')
		  {
			  s1[i]=s1[i]+32;
			 }
	}

   printf("the lower case is %s",s1);
   return 0;



}
