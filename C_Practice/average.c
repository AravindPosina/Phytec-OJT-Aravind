#include<stdio.h>
int main()
{
	int i,total;
	int a[]={12345};
	int n=5;
	total=0;
	for(i=0;i<n;i++)
	{
		total+=a[i];
	}
	printf("average =%f\n",total/(float)n);
	return 0;
}


