#include<stdio.h>
int main()
{
	int a[]={6,7,8,9,11,12,15,16,17,18,19};
	int len=sizeof (a)/sizeof a[0];
	int diff=a[0]-0;
	for (int i=0;i<len;i++)
	{
		if (a[i]-i!=diff)
		{
			while(diff<a[i]-i)
			{
				printf("missing element %d\n",i+diff);
				diff++;
			}

		}
	}

}

