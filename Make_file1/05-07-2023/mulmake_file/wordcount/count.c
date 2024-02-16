#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void num(void)
{
	int totalwords=0;
	int totalchars=0;
	int totallines=0;
	int boolean;
	int n;
	while((n=getchar())!=EOF)
	{
		totalchars++;
		if (isspace(n) && isspace(getchar()))
		{
			totalwords++;
		}

		if (n=='\n')
		{
			totallines++;
		}
		if (n=='-')
		{
			totalwords--;
		}
	}
	printf("chars,words,lines\n");
	printf("%d,%d,%d\n",totallines,totalwords,totalchars);
}

