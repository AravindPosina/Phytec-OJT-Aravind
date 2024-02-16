#include<stdio.h>
void even (void)
{
	int number;
	printf("enter the number");
	scanf("%d",&number);
	if (number%2==0)
	{
		printf("your number is % d and its an even number",number);
	}
}

