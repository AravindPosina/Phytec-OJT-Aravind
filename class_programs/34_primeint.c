#include<stdio.h>
int main()
{
	int i,j,num1,num2;
	printf("Enter a number : ");
	scanf("%d",&num1);
	printf("Enter a number : ");
	scanf("%d", &num2);
	for(i=num1+1;i<num2;i++)
	{
		int count = 0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				count++;
		}
		if(count==1)
		{
			printf("%d",i);
		}
}
}


