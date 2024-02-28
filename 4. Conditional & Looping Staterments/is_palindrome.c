#include<stdio.h>
int main()
{
	int num,temp,rem=0,res;
	printf("Enter number: ");
	scanf("%d",&num);

	temp=num;
	while(num)
	{
		res=num%10;
		rem=res+10*rem;
		num=num/10;
	}
	if(temp==rem)
		printf("The number is palindrome");
	else
		printf("The number is not palindrome");

	
	
}
