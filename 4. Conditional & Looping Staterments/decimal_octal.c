#include<stdio.h>
int main()
{
	int num,result=0,place=1,rem;
	printf("Enter number: ");
	scanf("%d",&num);
	while(num)
	{
		rem=num%8;
		result=result+rem*place;
		place=place*10;
		num=num/8;
	}
	printf("The octal number is: %d",result);
}
