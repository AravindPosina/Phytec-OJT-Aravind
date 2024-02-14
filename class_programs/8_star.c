#include<stdio.h>
int main()
{
	int r,i,j,k;
	printf("Enter the rows : ");
	scanf("%d",&r);
	for(i=0;i<r;i++)
	{
		for(j=0;j<i;j++)
		{
			printf(" ");
		}
		for(k=0;k<r-i;k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
