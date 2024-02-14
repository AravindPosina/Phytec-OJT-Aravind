#include<stdio.h>
#include "mylib.h"

void print(char *str, int times)
{
	while(times--)
	{
		printf("%s",str);
	}
}
