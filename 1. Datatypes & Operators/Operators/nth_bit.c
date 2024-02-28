#include<stdio.h>
int main()
{
	int num,n;
	printf("Enter the number: ");
	scanf("%d",&num);
	printf("Enter the position of bit to print: ");
	scanf("%d",&n);
	for(int i=0;i<16;i++)
	{
		if(i==n)
		{
			if(num&1<<i-1)
			{
				printf("Bit is 1\n");
			}
			else{
				printf("Bit is 0\n");
			}
		}
	}

}
