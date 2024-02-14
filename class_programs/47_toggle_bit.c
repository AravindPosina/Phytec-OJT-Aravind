#include<stdio.h>
int main()
{
	int num,n;
	printf("Enter a number: ");
	scanf("%d",&num);

	printf("Enter a bit number to toggle: ");
	scanf("%d",&n);
	 
	int bit=1<<n-1;
	int value=num^bit;

	printf("After toggle %d",value);
}

