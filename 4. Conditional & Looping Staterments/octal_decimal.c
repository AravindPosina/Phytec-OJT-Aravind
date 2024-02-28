#include<stdio.h>

int main()
{
        int place=1,rem,num,result=0;
        printf("Enter number: ");
        scanf("%d",&num);
        while(num)
        {
                rem=num%10;
                result=result+rem*place;
                place=place*8;
                num=num/10;
        }
        printf("The decimal number is:%d ",result);
}
