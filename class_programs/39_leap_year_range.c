#include<stdio.h>
void main()
{
	int min,max;
	printf("enter year range:\n");
	scanf("%d-%d",&min,&max);
	for(int i=min;i<=max;i++)
	{
		if((i%100!=0)&&(i%4==0)||(i%400==0))
		{
			printf("leap year is %d\n",i);

		}
		else
			printf(" not leap year is %d\n",i);
		
	}
}
