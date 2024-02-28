#include<stdio.h>
int main()
{
	int n,i,count=0;
	printf("Enter a number: ");
	scanf("%d",&n);

	for(i=2;i<n;i++)
	{
		if(n%2 == 0)
		{
			count++;
		}
	}
	if(count>1)
	{
		printf("%d is not a prime number",n);
	}
	else
	{
		printf("%d is a prime number",n);
	}
}

