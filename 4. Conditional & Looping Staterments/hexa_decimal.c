#include<stdio.h>
int main()
{
	int num,result=0,place=1,rem;
	printf("Enter number: ");
	scanf("%d",&num);
	while(num)
	{
		rem=num%10;
		result=result+rem*place;
		place=place*16;
		num=num/10;
	}
	printf("The decimal number is: %d",result);
}
