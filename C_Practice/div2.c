#include<stdio.h>
int main()
{
	int i;
	for(i=1;i<100;i++)
	{
                  
		if(i%2==0)
			printf("%d ",i);
	}	
	printf("\n");
	for(i=1;i<100;i++)
	{
		if(i%3==0)
			printf("%d ",i);
	}	
	printf("\n");
	for(i=1;i<100;i++)
	{	
		if(i%2==0 && i%3==0)
	 		printf("%d ",i);
	}	
}

