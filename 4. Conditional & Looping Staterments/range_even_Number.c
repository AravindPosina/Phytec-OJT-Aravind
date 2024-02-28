#include<stdio.h>
int main()
{
        int i,num,range;
        printf("Enter the starting number: ");
        scanf("%d",&num);
	printf("Enter the ending number: ");
	scanf("%d",&range);
        printf("The Even numbers between %d to %d is: ",num,range);
        for(i=num;i<range;i++)
        {
		if(i%2==0)
                printf("\n%d\n",i);
        }
}

