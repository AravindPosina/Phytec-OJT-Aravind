#include<stdio.h>
int main()
{
	int r,i,j;
	printf("Enter the rows: ");
	scanf("%d",&r);
	for(i=0;i<r;i++)
	{
		for(j=0;j<r-i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

