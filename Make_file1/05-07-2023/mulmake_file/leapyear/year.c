#include<stdio.h>
void year (void)
{
	int year;
	printf("enter the year");
	scanf("%d",&year);
	if (year % 4 == 0)
		printf("%d is a leap year:",year);
	else
		printf("%d is a not a leap year:",year);
}


