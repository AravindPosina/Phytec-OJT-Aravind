#include<stdio.h>
int main()
{
	int i,j,num;
	printf("Enter the number: ");
	scanf("%d",&num);
	for(i=2;i<num;i++)
	{
		int count=0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				count++;
		}
		if(count==1)
			printf("%d",i);
	}
}
