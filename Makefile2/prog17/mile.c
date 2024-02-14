#include<stdio.h>
void mileage(void) {
	int b,a,t,r;

	printf("Mileage before: \n");
	scanf("%d",&b);
	printf("Mileage after ride: \n");
	scanf("%d",&a);
	t=a-b;
	printf("Total travelled: %d",t);
	r=t*20;
	printf("Price of total ride: %d",r);
	}
