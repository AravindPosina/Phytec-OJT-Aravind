#include<stdio.h>
int len() //length of the array
{
	int size,i,a;
	int len =sizeof (arr)/sizeof arr[0];
	for(i=0;i<size;i++)
	{
		printf("%d",len);
	}

}

int main()
{
	int size,i;
	printf("enter the array size =");//get input 
	scanf("%d",&size);
	int arr[size];
	printf("enter %d element of an array=",size);
	for(int i=0;i<size;i++)	//scanning the array
	{
		scanf("%d",&arr[size]);
	}
	len(a,size);
	printf("\n");

}



