#include<stdio.h>
int maxarray(int[],int);
int main()
{
	int arr[]={1,2,9,6,4,};
	int max_element=maxarray(arr,5);
	printf("max element in array =%d",max_element);
	return 0;
}
int maxarray(int  array[],int n)
{
	int max_element = array[0],i;
	for(i=0;i<n;i++)
	{
		if (array[i]>max_element)
		{
			max_element=array[i];
		}
	}

	return max_element;
}

