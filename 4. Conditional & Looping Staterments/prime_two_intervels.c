#include<stdio.h>
int main()
{
	int num1,num2,i,j;
	printf("Enter number 1: ");
	scanf("%d",&num1);
	printf("Enter number 2: ");
	scanf("%d",&num2);
	printf("The prime numbers are: \n"); 
        for(i=num1+1;i<num2;i++)
        {
                int count=0;
                for(j=1;j<i;j++)
                {
                        if(i%j==0)
                                count++;
                }
                if(count==1)
                        printf("%d\n",i);
        }
}


