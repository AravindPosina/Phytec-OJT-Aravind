#include<stdio.h>
#include"maxpointer.h"
int main()
{
	int n,i;
	printf("Enter the size of an array\n");
	scanf("%d",&n);
	int a[n];
	int *pint;
	int max;
	pint=a;
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=pint;
	for (i=1;i<n;i++)
	{
		if (*(pint+i)>max)
		{
			max=*(pint+i);
		}
	}
	printf("THe maximum value is ::%d\n",max);
}
