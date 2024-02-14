#include<stdio.h>
void main()
{
	int mat[3][3];
	int sum=0;
	int k,l;
	printf("enter matrix:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for( k=0;k<3;k++)
	{
		for( l=0;l<3;l++)
		{
			if(k>=l)
			{
				sum=sum+mat[k][l];
			}
		}
	}
	printf("lower triangle sum is :%d\n",sum);
}



