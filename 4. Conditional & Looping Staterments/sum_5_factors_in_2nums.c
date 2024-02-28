#include<stdio.h>
int main()
{       
        int num1,num2,i,j,temp=0;
        printf("Enter the num1: ");
        scanf("%d",&num1);
        printf("Enter the num2: ");
        scanf("%d",&num2);
        for(i=num1+1;i<num2;i++)
        {
                if(i%5==0)
                {
                        temp=temp+i;
                }
        }
        printf("%d",temp);
}

