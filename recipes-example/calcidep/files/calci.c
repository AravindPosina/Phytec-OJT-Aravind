#include<stdio.h>
#include<mylib.h>

int main()
{
	int a,b;
	printf("Enter a : ");
	scanf("%d",&a);
	printf("Enter b : ");
	scanf("%d",&b);
	int c;
	c=add(a,b);
	printf("Addition = %d",c);
	c=sub(a,b);
	printf("substraction = %d",c);
	c=mul(a,b);
	printf("multiplication = %d",c);
	c=div(a,b);
	printf("Division = %d",c);
}
