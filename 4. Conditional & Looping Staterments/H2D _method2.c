#include<stdio.h>
#include<math.h>
int main()
{
        int place=0,rem,num,result=0;
        printf("Enter number: ");
        scanf("%d",&num);
        while(num)
        {
                rem=num%10;
                result=result+rem*pow(16,place);
                place++;
                num=num/10;
        }
        printf("The binary number is:%d ",result);
}
