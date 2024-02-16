#include<stdio.h>
void num(void)
{
	int i,j,a,n,number[50];
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the number\n");
	for (i=0;i<n;i++)
	
		scanf("%d",&number[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(number[i]>number[j])
			{
				a=number[i];
				number[i]=number[j];
				number[j]=a;
			}
		}
	}
	printf("the number of arranged\n");
	for (i=0;i<n;i++)
		printf("%d",number[i]);
}

