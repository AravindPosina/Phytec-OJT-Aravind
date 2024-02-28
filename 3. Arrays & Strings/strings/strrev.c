#include<stdio.h>
#include<string.h>
int main()
{
	int size,i;
	char str[10];
	printf("enter a string: ");
	gets(str);
	size=strlen(str);
	for(i=size-1;i>=0;i--)
	{
		printf("%c",str[i]);
	}
}
