#include<stdio.h>
int main()
{
	int a[]={6,7,8,9,10,11,13,14,15,16,17};
	int s1,sum,s2,sum1,s=0,diff;
	int len= sizeof (a)/sizeof a[0];
	int max=a[len-1];
	s1=max*(max+1);
	sum=s1/2;
	int min=a[0]-1;
	s2=min*(min+1);
	sum1=s2/2;
	for(int i=0;i<len;i++)
	{
		s=s+a[i];
	}
	diff=sum-sum1-s;
	printf("diff %d",diff);
	return 0;
}


