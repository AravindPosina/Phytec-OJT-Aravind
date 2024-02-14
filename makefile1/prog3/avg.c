#include<stdio.h>
#include"avg.h"
int main() {
	int a,b,c,d;
	printf("enter a:");
	scanf("%d",&a);
	printf("enter b:");
	scanf("%d",&b);
	printf("enter c:");
	scanf("%d",&c);
	printf("enter d:");
	scanf("%d",&d);
	avg = (a+b+c+d)/4;
	printf("avg of %d,%d,%d, and %d numbers is:%f",a,b,c,d,avg);
}
