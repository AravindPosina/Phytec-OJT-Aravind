#include<stdio.h>
#include"fileread.h"
int main()
{
	FILE *fp;
	fp=fopen("file1","w");
	if (fp == NULL)
	{
		printf("File not found\n");
	}
	else
	{
		printf("File is present and opened for writing:\n");
		fclose(fp);
	}
}
