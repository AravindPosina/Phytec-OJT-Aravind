#include<stdio.h>
int main()
{
	int i,j,n,sum=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
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




