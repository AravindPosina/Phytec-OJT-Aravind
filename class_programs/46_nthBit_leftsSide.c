#include<stdio.h>
void main()
{
	int num,bit;
	printf("enter decimal number:\n");
	scanf("%d",&num);
	printf("enter nth bit:\n");
	scanf("%d",&bit);
			num=num<<bit;

	printf("%d\n",num);
      	
}

