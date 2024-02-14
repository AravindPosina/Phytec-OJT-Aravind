#include<stdio.h>
int main()
{
	int num;
	printf("enter a number : ");
	scanf("%d",&num);
	if(num & (1<<15))
	{
		printf("1");
	}
	else
		printf("0");
}
