#include<stdio.h>
#include"str_search.h"
void str_search()
{
	char a[] ="Saishitha";
	int x;
        for(int i=0;a[i];i++)
	{
		if(a[i]=='n')
		{
			x=i+1;
		}
	}
	printf("the position of the character is: %d\n",x);
}
