
#include<stdio.h>
int main()
{
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};


	for(int i=0;i<3;i++)
	{
		for(int j=3-1;j<=3;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<3;i++)
	{
		for(int j=3-1;j>=0;j--)
		{
			printf("%d\t",a[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=2;i<0;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",a[j][i]);
		}
		printf("\n");
	}
	return 0;
}

