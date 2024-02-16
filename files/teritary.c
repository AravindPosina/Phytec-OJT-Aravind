#include<stdio.h>
int main()
{
	int a,b,max;
	printf("enter any two number \n");
	scanf("%d%d",&a,&b);
	max=(a<b)? a:b;
	printf("%d\n",max);
	printf("is the largest number of given number");
	return 0;
}

