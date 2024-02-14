#include<stdio.h>
int main()
{
	int num,lsb;
	printf("enter the number: ");
	scanf("%d",&num);
	lsb= num & 1;
	printf("LSB of number is %d",lsb);
}
