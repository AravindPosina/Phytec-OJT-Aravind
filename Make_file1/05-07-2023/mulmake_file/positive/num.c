#include<stdio.h>
void num(void)
{
	double num;
	printf("enter the number:");
	scanf("%lf",&num);
	if (num<=0.0)
	{
		if (num == 0.0)
			printf("you entered 0.0");
		else 
			printf("you entered neagtive number:");
	}
	else 
		printf("you entered a neagtive number");
}

