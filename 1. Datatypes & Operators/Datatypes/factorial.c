#include<stdio.h>
int main()
{
        int n,i,fact=1;
        printf("Enter a number: ");
        scanf("%d",&n);

	for(i=n;i>0;i--)
	{
		fact=fact*i;
	}
	printf("The factorial of %d is %d",n,fact);
}


