#include<stdio.h>
int main()
{
	int num,i,sum=0,temp;
	printf("Enter the number: ");
	scanf("%d",&num);
	temp=num;
	for(i=1;i<num;i++)
	{
		if(num%i==0)
		{
			sum=sum+i;
		}
	}
	if(temp==sum)
		printf("The number is perfect number");
	else
		printf("The number is not perfect number");
}
	

