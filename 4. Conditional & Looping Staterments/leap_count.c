#include<stdio.h>
int main()
{
	int a,b,count=0;
	printf("Enter start and end year: ");
	scanf("%d%d",&a,&b);
	printf("Leap Years:\n");
	for(int i=a;i<=b;i++)
	{
		if(i%400==0 || i%4==0 && i%100!=0)
		{
			printf("%d\n",i);
			count++;
		}
	}
	printf("Count=%d\n",count);
}
