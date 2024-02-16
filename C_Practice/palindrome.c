#include<stdio.h>
int main()
{
	int number,temp,reverse=0,reminder;
	printf("enter the number\n");
	scanf("%d",&number);
	temp=number;
	while (number!=0)
	{
		reminder=number%10;
		reverse=reverse*10+reminder;
		number =number/10;
	}
	if (reverse==temp)
		printf("the number is palindrome");
	else
		printf("it is not palindrome");
	return 0;
}

