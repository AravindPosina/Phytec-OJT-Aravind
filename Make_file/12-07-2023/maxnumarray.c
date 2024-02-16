#include<stdio.h>
int largest(int arr[],int n)
{
	int i;
	int max=arr[0];
	for(i=0;i<n;i++)
		if(arr[i]>max)
			max=arr[i];
		return max;
}
int main()
{
	int arr[]={3,6,8,8,10,12,15,15,15,20};
	int n=sizeof (arr)/sizeof arr[0];
	printf("largest in the array %d\n",largest(arr,n));
	return 0;
}

			
