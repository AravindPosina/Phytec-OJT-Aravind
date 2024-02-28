#include<stdio.h>
int main()
{
	int num,rem=0,res,temp;
	printf("Enter number: ");
	scanf("%d",&num);
	temp=num;
	while(num)
	{
		res=num%10;
		rem=rem+res*res*res;
		num=num/10;
	}
	if(temp==rem)

		printf("The number is amstrong number");
	else
		printf("The number is not a amstrong number");
}
