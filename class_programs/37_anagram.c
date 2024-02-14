#include<stdio.h>
#include<string.h>
int main()
{
	int len1,len2,i,j;
	char str1[14],str2[14],temp;
	printf("enter string1: ");
	scanf("%s",str1);
	printf("enter string2: ");
	scanf("%s",str2);
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1!=len2)
	{
		printf("Both strings length is not same");
	}
	for(i=0;i<=len1;i++)
		{
			for(j=0;j<=len2;j++)
			{
				if(str1[i]>str1[j])
				{
					temp=str1[i];
					str1[i]=str1[j];
					str1[j]=temp;
				}
				if(str2[i]>str2[j])
				{
					temp=str2[i];
					str2[i]=str2[j];
					str2[j]=temp;
				}
			}
		}
	for(i=0;i<=len1;i++)
		{
			if(str1[i]!=str2[i])
			{
				printf("strings are not anagram");
				return 0;
			}
		}
		printf("strings are Anagram");
	}
