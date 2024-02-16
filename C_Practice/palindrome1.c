#include<stdio.h>
int main()
{
	int reverse=0,reminder,number,temp;

	printf("enter the number\n");
	scanf("%d",&number);
	temp=number;
	while(number!=0)
	{
		reminder=number%10;
		reverse=reverse*10+reminder;
		number=number/10;
	}
	if (temp==reverse)
		printf("the entered %d number is palindrome\n",temp);
	else
		printf("the entered %d number is not palindrome \n",temp);
	return 0;

}

