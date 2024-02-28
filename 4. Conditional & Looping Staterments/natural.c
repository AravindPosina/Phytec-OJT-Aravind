#include<stdio.h>
int main()
{
	int i,range;
	printf("Enter the range of Natural numbers: ");
	scanf("%d",&range);
	printf("The natural numbers are: ");
	for(i=1;i<=range;i++)
	{
		printf("\n%d\n",i);
	}
}
