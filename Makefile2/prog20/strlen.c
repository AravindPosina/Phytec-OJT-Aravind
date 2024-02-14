#include<stdio.h>
#include<string.h>
void str_demo(char *a,char *b)
{
	int k;
	k=strcmp(a,b);
	if(k=0) {
		printf("Both strings are equal\n");
	}
	else
		printf("Both strings are not equal\n");
}
