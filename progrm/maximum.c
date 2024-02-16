#include<stdio.h>
int main()
{
	int num1,num2;
	printf( "enter the two integer\n");
	scanf("%d %d", &num1,&num2);
	if(num1>num2)
	{
		printf("%d  is larger\n",num1);
	}
	else if (num2>num1)
	{
		printf("%dis larger\n",num2);
	}
	else
	{
		printf("both are equal\n");
	}
	return 0;
}	
