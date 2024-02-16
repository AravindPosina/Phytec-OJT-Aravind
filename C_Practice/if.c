#include<stdio.h>
int main()
{
	int number;
	printf("enter the number");
	scanf("%d",&number);
	if (number%2==0)
	{
		printf("your number %d and it is an even number",number);
	}
	return 0;
}

