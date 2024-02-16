#include<stdio.h>
void num (void)
{
	int num1,num2;
	printf("enter the two number\n");
	scanf("%d %d",&num1,&num2);
	if(num1>num2)
	{
		printf("%d is larger \n",num1);
	}
	else if(num1<num2)
	{
		printf("%d id larger \n",num2);
	}
	else
	{
		printf("both are equal \n");
	}

}

