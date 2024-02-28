#include<stdio.h>
int main()
{       
        int a[14],size;
        printf("enter size: ");
        scanf("%d",&size);
        for(int i=0;i<=size;i++)
        {
                printf("array element %d:",i+1);
                scanf("%d",&a[i]);
        }
	for(int i=0;i<=size;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}     
