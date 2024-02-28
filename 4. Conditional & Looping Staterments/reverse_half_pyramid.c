#include<stdio.h>
int main()
{
        int rows,i,j;
        printf("Enter the number of rows: ");
        scanf("%d",&rows);
        for(i=rows;i>0;i--)
        {
                for(j=1;j<=i;j++)
                {
                        printf("*");
                }
                        printf("\n");

        }
}

