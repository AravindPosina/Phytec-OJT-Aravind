#include<stdio.h>
void main()
{
	int mat1[2][2];
	int mat2[2][2];
	int mat3[2][2];
	printf("enter mat1\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
		scanf("%d",&mat1[i][j]);
	}
	}
	printf("enter mat2\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
          	scanf("%d",&mat2[i][j]);
		}
	}
	printf("output is:\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d ",mat1[i][j]+mat2[i][j]);
		}
		printf("\n");
	}
}
