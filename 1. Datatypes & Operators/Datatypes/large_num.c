#include<stdio.h>
int main()
{
        int range,num,num2,i;
        printf("Enter range: ");
        scanf("%d",&range);
        if(range <=0)
        {
                printf("Enter valid range");
        }
        printf("enter num1: ");
        scanf("%d",&num);

        for(i=2;i<=range;i++)
        {
                printf("enter num%d: ",i);
                scanf("%d",&num2);
                if(num2>num)
                {
                        num=num2;
                }
        }
        printf("The largest  number is %d",num);
}


