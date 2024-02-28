#include<stdio.h>
int main()
{
	char name[20];
	printf("Enter the string: ");
	//fgets(name,sizeof(name),stdin);
	gets(name);
	int i, vov=0,con=0;
	for(i=0;name[i]!='\0';i++)
	{
		if(name[i]=='A'||name[i]=='E'||name[i]=='I'||name[i]=='O'||name[i]=='U'||name[i]=='a'||name[i]=='e'||name[i]=='i'||name[i]=='o'||name[i]=='u')
			continue;
		else
			printf("%c",name[i]);

}
