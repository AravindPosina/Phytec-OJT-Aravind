#include<stdio.h>
int main()
{
	int a[]={1,2,3,4,5,6,8,9,10,11,12};
	int s=0,diff;
        int len= sizeof (a)/sizeof a[0];
	int max= a[len-1];
	int s1= max*(max+1);
	int sum= s1/2;
	for(int i=0;i<len;i++)
	{
		s=s+a[i];
	}
	diff=sum-s;
	printf("diff %d",diff);
	return 0;

}

