#include<stdio.h>
int main()
{
	int num1,num2,num3;
	printf( "enter the three integer\n");
	scanf("%d %d %d", &num1,&num2,&num3);
	if(num1>=num2&&num1>=num3)
		printf("%2d is the largest number \n", num1);
	
	else if (num2>=num1&&num2>=num3)
		printf("%2d is the largest number \n", num2);
	else(num3>=num1&&num3>=num2);
		printf("%2d is the largest number \n", num3);

	return 0;

}	
