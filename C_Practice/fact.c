#include<stdio.h>
long int facto(int n)
{
if(n==1)
{
return 1;
}
else return n*facto(n-1);
}
void main()
{
long  int f;
int num;
printf("Enter any number :");
scanf("%d",&num);
if(num>0)
{
f=facto(num);
printf("factorial is %d",f);
}
else
{
	printf("\n error:given number is  %d negative",num);
}
}
