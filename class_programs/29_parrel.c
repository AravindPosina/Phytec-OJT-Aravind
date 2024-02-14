#include<stdio.h>
int main()
{
        int x1,x2,x3,x4,y1,y2,y3,y4,m1,m2;
        printf("Enter the value x1: ");
        scanf("%d",&x1);
        printf("Enter the value x2: ");
        scanf("%d",&x2);
        printf("Enter the value x3: ");
        scanf("%d",&x3);
        printf("Enter the value x4: ");
        scanf("%d",&x4);

        printf("Enter the value y1: ");
        scanf("%d",&y1);
        printf("Enter the value y2: ");
        scanf("%d",&y2);
        printf("Enter the value y3: ");
        scanf("%d",&y3);
        printf("Enter the value y4: ");
        scanf("%d",&y4);

        m1=y2-y1/x2-x1;
        m2=y4-y3/x4-x3;

        if(m1==m2)
                printf("The lines are parallel");
        else
                printf("The lines are not parallel");
}
