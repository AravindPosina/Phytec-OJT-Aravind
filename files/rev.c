#include<stdio.h>
int main()
{
	int number,reminder,reverse=0;
	printf("enter the number\n");
	scanf("%d",&number);
	while (number >=1)
	{
		reminder=number%10;
		reverse=reverse*10+reminder;
		number=number/10;	
	}
		printf("\nthe reversed number %d",reverse);
		return (0);
}

