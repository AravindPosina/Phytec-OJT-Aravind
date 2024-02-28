#include<stdio.h>
int main()
{
	int place=1,rem,num,result=0;
	printf("Enter number: ");
	scanf("%d",&num);
	while(num)
	{
		rem=num%2;
		result=result+rem*place;
		place=place*10;
		num=num/2;
	}
	printf("The binary number is:%d ",result);
}
