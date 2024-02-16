#include<stdio.h>
int main()
{
	int a[3][3]={{8,3,9},{3,5,17},{2,8,6}};
	int i,j;
	int sum=0;
	//ROW SUM
	printf("ROW Total\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=sum+a[i][j];
		}
		printf("Sum of %d row is %d\n",i+1,sum);
		sum=0;
	}
	//COLUMN SUM
        printf("COLUMN Total\n");
        for(j=0;j<3;j++)
        {
                for(i=0;i<3;i++)
                {
                        sum=sum+a[i][j];
                }
                printf("Sum of %d column is %d\n",j+1,sum);
                sum=0;
        }
	return 0;
}
