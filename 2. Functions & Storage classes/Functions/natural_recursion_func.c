#include<stdio.h>

void Naturalnumbers(int lowerlimit,int upperlimit);

int main()
{
	int lowerlimit,upperlimit;
	printf("Enter the lower limit: ");
	scanf("%d",&lowerlimit);
	printf("Enter the upperlimit: ");
	scanf("%d",&upperlimit);
	printf("The natural numbers between %d and %d is\n",lowerlimit,upperlimit);
        Naturalnumbers(lowerlimit+1,upperlimit);
	return 0;
}
void Naturalnumbers(int lowerlimit,int upperlimit)
{
	if(lowerlimit>=upperlimit)
	{
		return;
	}
		printf("%d ",lowerlimit);
		
		Naturalnumbers(lowerlimit +1,upperlimit);
		
	
}

