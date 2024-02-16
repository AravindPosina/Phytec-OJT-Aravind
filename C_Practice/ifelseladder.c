#include<stdio.h>
int main()
{
	int number=0;
	printf("enter the number\n");
	scanf("%d",&number);
	if (number==10)
	{
		printf("the entered number is equal to 10\n");
	}
	else if (number==20)
	{
		printf("the entered number is equal to 20\n");
	}
	else if (number==30)
	{
		printf("the entered number is equal to 30\n");
	}
	else
	{
		printf("the entered number is not equal to 10,20,30\n");
	}
	return 0;
}	
