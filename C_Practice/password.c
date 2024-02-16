#include<stdio.h>
int main()
{
 char pass [20],e_pass[20];
 int num1 , num2, sum;
 printf("create a password");
 scanf ("%s", pass);
 printf("\n enter any two number to add :");
 scanf ("%d%d",&num1,&num2);
 printf("\n enter password to see the result:");
 scanf("%s",e_pass);
  if (!strcmp/pass,e_pass)
   {
     sum=num1+num2;
     printf("\n%d+%d=%d",num1,num2,sum);
    
  else
     printf("\n sorry: you entered wrong");
    }
 getch();
 return 0;
}
