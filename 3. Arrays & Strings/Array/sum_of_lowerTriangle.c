#include<stdio.h>
int main()
{
	int a[3][3],i,j,sum=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("enter matrix elements: ");
			scanf("%d",&a[i][j]);
			if(i==j||j==0||i==2)
				sum=sum+a[i][j];
		}
	}
	printf("sum =%d",sum);
}

