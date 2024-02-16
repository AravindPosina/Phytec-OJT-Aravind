#include<stdio.h>
void num(void)
{
	int num;
	printf("enter the number:\n");
	scanf("%d",&num);
	if(num % 2 == 0)
		printf("%d is even:",num);
	else
		printf("%d is odd:",num);
}

