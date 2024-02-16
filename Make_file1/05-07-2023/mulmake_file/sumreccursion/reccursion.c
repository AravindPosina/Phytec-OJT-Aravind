#include<stdio.h>
void reccursion(void)
{
	int num;
	printf("enter a positive integer:");
	scanf("%d", &num);
	printf("sum = %d", addnumbers(num));
	return 0;
}


int addnumbers(int n);
{
	if (n != 0)
		return n + addnumbers(n-1);
	else
		return n;
}



