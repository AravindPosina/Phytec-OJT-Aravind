#include<stdio.h>
int main()
{
	int num,i,count=0;
	printf("Enter number: ");
	scanf("%d",&num);
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			count++;
		}
	}
		if(count>1)
			printf("The number is not prime");
		else
			printf("The number is prime");
	
}
