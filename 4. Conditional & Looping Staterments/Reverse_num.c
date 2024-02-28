#include<stdio.h>
int Reverse(int num);

int Reverse(int num)
{
	int rem=0,res;	
	int num1=num;
	while(num)
	{
		res=num%10;
		rem=rem*10+res;
		num=num/10;
	}
	printf("%d",rem);
}
int main()
{
	int num;
	printf("Enter the number: ");
	scanf("%d",&num);
	Reverse(num);
}
