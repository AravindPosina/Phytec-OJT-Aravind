#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("Enter num1: ");
	scanf("%d",&a);
	printf("Enter num2: ");
	scanf("%d",&b);
	printf("Enter num3: ");
	scanf("%d",&c);
	printf("Enter num4: ");
	scanf("%d",&d);

	if(a>b&&a>c&&a>d)
		printf("%d bigger",a);
	else if(b>c&&b>d)
		printf("%d is bigger",b);
	else if(c>d)
		printf("%d is bigger",c);
	else
		printf("%d is bigger",d);
	
	if(a<b&&a<c&&a<d)
	
                printf("\n%d is smaller",a);
        else if(b<c&&b<d)
                printf("\n%d is smaller",b);
        else if(c<d)
                printf("\n%d is smaller",c);
        else
                printf("\n%d is smaller",d);
	

}
