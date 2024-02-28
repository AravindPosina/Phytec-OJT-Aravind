#include<stdio.h>
int main()
{
	int rows,i,j;
	char c='A';
	printf("Enter the rows: ");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%c",c);
			c++;
		}
		printf("\n");
	}
}
