#include<stdio.h>
int main()
{
	int v1,v2;
	printf("enter the number v1\n");
	scanf("%d",&v1);
	printf("enter the number v2\n");
	scanf("%d",&v2);
	if (v1 != v2)
	{
		printf("the v1 and v2 are not equal\n");
		if (v1<v2)
		{
			printf("the v2 is greater");
		}
		else
		{
			printf("the v1 is greater");
		}
	}		
	else
	{
		printf("the v1 and v2 are equal\n");
	}
	return 0;
}
