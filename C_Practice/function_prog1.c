#include<stdio.h>
int add()
{
	int sum,a=10,b=3;
	sum =a+b;
}
int sub()
{
	int subs,a=3,b=5;
	subs=a-b;
}
int mul()
{
	int mult,a=4,b=6;
	mult=a*b;
}
int div()
{
	int divi,a=10,b=5;
	divi=a/b;

}
int mod()
{
	int modu,a=10,b=5;
	modu=a%b;
}

int main()
{
	int sum = add();
	int subs = sub();
	int mult = mul();
	int divi = div();
	int modu = mod();
	printf("%d\r\n",sum);
	printf("%d\r\n",subs);
	printf("%d\r\n",mult);
	printf("%d\r\n",divi);
	printf("%d\r\n",modu);
	return 0;
}

