#include<stdio.h>
#include<math.h>
int product(int num1,int num2)
{
	int product;
	if (num1&&num2>0)
	{
		product=((num1-num2)*(num1-num2)*(num1-num2));
		printf("product of the number %d:\n",product);
		return 0;
	}
	else
		return 0;

}
int main()
{
	int num1,num2;
	printf("enter the num1:\n");
	scanf("%d",&num1);
	printf("enter the num2:\n");
	scanf("%d",&num2);
	product(num1,num2);
	return 0;
	
}
