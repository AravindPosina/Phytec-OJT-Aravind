#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int totalwords=0;
	int totalchars=0;
	int totallines=0;
	int boolean;
	int n;
	while((n=getchar())!=EOF)
	{
		totalchars++;
		if (isspace(n) && !isspace(getchar()))
		{
			totalwords++;
		}
		if (n=='\n')
		{
			totallines++;
		}
		if(n=='-')
		{
			totalwords--;
		}
	}
	printf("chars,words,lines\n");
	printf("%3d,%3d,%3d\n",totallines,totalwords,totalchars);
	return 0;
}

