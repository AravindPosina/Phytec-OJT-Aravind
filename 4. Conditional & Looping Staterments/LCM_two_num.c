#include<stdio.h>
int main()
{
	int a,b,num1,num2,lcm,gcd,temp;
	printf("Enter num1: ");
	scanf("%d",&num1);
	printf("Enter num2: ");
	scanf("%d",&num2);
	a=num1;
	b=num2;
	while(b!=0)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	gcd=a;
	lcm=num1*num2/gcd;
	printf("The LCM of given numbers is %d",lcm);
}
	

