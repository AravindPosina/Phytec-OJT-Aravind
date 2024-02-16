#include<stdio.h>
int main()
{
	int decimal_number;
	printf("enter the decimal_number:");
	scanf("%d",&decimal_number);
	int i=1,j,temp;
	char hexa_number[1000];
	while(decimal_number!=0)
	{
		int ch=decimal_number/16;
		int r=ch*16;
		temp=decimal_number -r;
		if (temp<10)
			temp=temp+48;
		else
			temp=temp+55;
		hexa_number[i++]=temp;
		decimal_number =decimal_number/16;
	}
	printf("hexadecimal valueis:");
	for(j=i-1;j>0;j--)
		printf("%c",hexa_number[j]);
	return 0;
}
