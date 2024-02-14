#include<stdio.h>
void main()
{
	int num,bit;
	printf("enter number:\n");
	scanf("%d",&num);
	printf("enter nth bit for rorate right side:\n");
	scanf("%d",&bit);
	num=num>>bit;
	printf("after rotate right side decimal value is : %d\n",num);
}
