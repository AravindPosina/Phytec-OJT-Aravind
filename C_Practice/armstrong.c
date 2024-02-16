#include<stdio.h>
int main()
{
	int number,reminder,sum=0,temp;

	printf("enter the any number");
	scanf("%d",&number);
	for (temp=number;number!=0;number=number/10)
	{
		reminder=number%10;
		sum=sum+(reminder*reminder*reminder);
	}
	if (sum==temp)
	printf("entered number is %d armstrong",temp);
	else
	printf("entered nuumber is %d not armstrong",temp);
	return 0;
	
}

