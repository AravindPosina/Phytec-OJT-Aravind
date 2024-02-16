#include<stdio.h>
int main()
{
	int number1,number2,sum;
	printf("enter the two integer number:");
	scanf("%d %d", &number1, &number2);
	sum=number1 + number2;
	printf("%d + %d =%d",number1, number2, sum);
	return 0;
}
