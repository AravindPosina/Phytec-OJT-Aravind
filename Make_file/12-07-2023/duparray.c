#include<stdio.h>
int main()
{
 	int arr[]={0,1,2,3,4,5,6,7,8,9};
	int n=sizeof (arr)/sizeof (arr[0]);
	int count=0;
	for(int i=0;i<n;i++)
	{
		printf("element-%d:",arr[i]);
		scanf("%d",&arr[i]);
	}

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{

			if ( arr[i]==arr[j])
			{
				printf("The duplicate number %d\n",arr[j]);
				count ++;
				break;
			}

		}
	}
	printf("the total duplicate number cound %d\n",count);
	return 0;
}



