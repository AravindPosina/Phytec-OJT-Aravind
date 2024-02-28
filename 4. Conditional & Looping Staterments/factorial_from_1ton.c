#include<stdio.h>
int main()
{
	int num,i,j,sum=0;
	printf("Enter number: ");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		int fact=1;
		for(j=1;j<=i;j++)
		{
			fact=fact*j;
		}
		sum=sum+fact;
	}
	printf("%d",sum);
}
