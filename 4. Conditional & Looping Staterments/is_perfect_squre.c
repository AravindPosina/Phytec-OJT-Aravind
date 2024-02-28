#include<stdio.h>
int main()
{
	int num,i,count=0;
	printf("Enter the number: ");
	scanf("%d",&num);
	for(i=1;i<num;i++)
	{
		if(i*i==num)
			count++;
	}
	if(count==1)
		printf("The number is perfect squre");
	else
		printf("The number is not perfect squre");
	
}
