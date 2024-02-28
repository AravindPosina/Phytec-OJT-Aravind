#include<stdio.h>
int main()
{
        int r,i,j,k;
        printf("Enter the rows : ");
        scanf("%d",&r);
        for(i=r;i>0;i--)
        {
                for(j=0;j<r-i;j++)
                {
                        printf(" ");
                }
                for(k=0;k<2*i-1;k++)
                {
                        printf("*");
                }
                printf("\n");
        }
}


