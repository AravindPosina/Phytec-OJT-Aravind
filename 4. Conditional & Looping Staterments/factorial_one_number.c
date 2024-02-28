#include<stdio.h>
int main()
{
	int fact=1,num,i;
	printf("Enter number: ");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		fact=fact*i;
	}
	printf("The factorial of %d is %d",num,fact);
}
