#include<stdio.h>
void main()
{
	char str[100], c=0,c1=0;
	//int i,j;
	printf("enter string\n");
	scanf("%s",str);

	for(int i=0;str[i]!='\0';i++)
	{
		if((str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u'))
		{
			c++;
		}
		else
		{
			c1++;
	}
	}
	printf("vowels is %d\n consonats is %d\n",c,c1);
	
}


