#include<stdio.h>
int main()
{
 	int vowels=0,consonants=0;
	char str[14];
	printf("enter string in lower case: ");
	scanf("%s",str);
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
		{
			vowels ++;
		}
		else
		{
			consonants ++;
		}
	}
	printf("%d is vowels %d is consonants",vowels,consonants);

}
