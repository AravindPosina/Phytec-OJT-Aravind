#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter the Values of a , b ");
	scanf("%d,%d", &a, &b );
	a=a+b;
	b=a-b;
	a=a-b;
	printf("The values of a=%d, b=%d\n", a, b);
	return 0;
}
