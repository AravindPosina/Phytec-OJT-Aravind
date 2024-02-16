#include<stdio.h>
void function1(void);
void function2(void);
void function3(void);
void main(void)
{
	int choice=0;
	printf("1.call function\n 2.call function\n 3.call function\n enter your choice[1-3]: ");
	scanf("%d",&choice);
	switch(choice)
	{
	case1:

     		function1();
     		break;

	case2:
     		function2();
		break;

	case3:
     		function3();
     		break;

	default:
     		printf("enter the valid function\n");
	}	
}
void function1(void)
{
	printf("this is function1\n");
}
void function2(void)
{
	printf("this is function2\n");
}
void function3(void)
{
	printf("this is function3\n");
}

