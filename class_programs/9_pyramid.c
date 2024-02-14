#include<stdio.h>
int main()
{
	int rows=5;
	for(int i=1;i<=rows;i++)
	{
		for(int j=i;j<=5;j++)
		{
			printf(" ");
		}
	for(int k=1;k<=i*2-1;k++)
	{
		printf("*");
	}
	printf("\n");
	}

}
