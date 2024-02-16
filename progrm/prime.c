#include<stdio.h>
void main()
{
	int n,i,f;
	i=2;
	f=0;
	printf("enter the number:");
	scanf("%d",&n);
	while(i<n)
	{
		if (n%i==0)
		{
			f=1;
			break;
		}
		i++;
	}
	if (f==1)
	{
	printf("\nnot a prime number");
	}
	else
	{
		printf("\n  prime number");
	}
}

