#include<stdio.h>
void main()
{
	int num,bit;
	printf("enter number:\n");
	scanf("%d",&num);
	printf("enter bit position:\n");
	scanf("%d",&bit);
	for(int i=0;i<16;i++)
		{
			if(bit==i)
			{
				if(num&(0x1<<i))
					printf("nth bit is :1\n");
				else 
					printf("nth bit is : 0\n");
			}
		}
}
	


