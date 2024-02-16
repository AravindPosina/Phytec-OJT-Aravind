#include<stdio.h>
int power(int n,int m)
{
	if (n!=0 && n % 2 == 0)
	{
		return (m*m)*(n/2);
		printf("%d",power(m,n));
	
	}
	else if(n!=0)
	{
		return (m*(n*m)^((n-1)%2));
		printf("%d",power(m,n));
	}
	else (n=0);
	{
		return 0;
	}
}

int main()
{
	int n,m;
	printf("enter the n:\n");
	scanf("%d\n",&n);
	printf("enter the m:\n");
	scanf("%d\n",&m);
	return 0;

}
