#include<stdio.h>
void num(void)
{
	int n,i;
	unsigned long long fact=1;
	printf("enter an integer:");
	scanf("%d",&n);
	if (n<0)
		printf("negative number does not have factorial");
	else
	{	
		for(i=1;i <= n;++i)
		{
			fact *=i;
		}
		printf("factorial of %d =%llu",n,fact);
	}

}

