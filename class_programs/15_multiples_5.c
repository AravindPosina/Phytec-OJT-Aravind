#include<stdio.h>
int main()
{
	int a,b,sum=0;
	printf("Enter the values of positive a and b values:");
	scanf("%d%d",&a,&b);
	if(a==b)
	{
		printf("there is no number between %d and %d\n",a,b);
	}
	else if(a>b)
	{
		printf("%d is greater than %d\n",a,b);
		a=a+b;
		b=a-b;
		a=a-b;
		printf("after swapping a=%d b=%d\n",a,b);
	}
	for(int i=a;i<=b;i++)
	{
		if(i%5!=0)
		{
			sum=sum+i;
		}

	}
	if(sum)
	{
		printf("sum of the numbers which are divisible by 5 between %d and %d is %d\n",a,b,sum);
	}
}
