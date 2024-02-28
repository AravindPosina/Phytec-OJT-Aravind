#include<stdio.h>
int main()
{
	char str1[14],str2[14];
	int count=0,i;
	printf("enter two strings:");
	gets(str1);
	gets(str2);
	int len=strlen(str1);
	for(i=1;i<=len;i++)
	{
		if(str1[i]!=str2[i])
		{
			count ++;
			break;
		}
	}
	if(count ==1)
	{
		printf("strings are not equal");
	}
	else 
	{
		printf("strings are same");
	}
}

