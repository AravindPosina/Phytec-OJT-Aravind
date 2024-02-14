#include<stdio.h>
#include"stringcpy.h"
int main() {
	char a[]="C programming";
	char b[30];
        int i, len=0;
	for(i=0;a[i];i++)

	{
		len++;
	}

	for(i=0;i<len;i++)

	{
		b[i]=a[len-i-1];
	}

	b[i]='\0';
	printf("After reversing::\n");
	printf("Original string=%s\n",a);
	printf("Reversed string=%s\n",b);
}
