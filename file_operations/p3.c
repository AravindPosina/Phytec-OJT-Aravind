/*The program takes a string from user and writes it to a file
character by character*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("Invalid number of arguments entered. Please \
				enter filename to display its contents....\n");
		exit(1);
	}
	
	FILE* fp=fopen(argv[1],"a"); /*opening the file in append mode*/
	if(fp==NULL)
	{
		perror("fopen() failed\n");exit(1);
	}

	/*taking input from the user*/
	char name[20];
	printf("Enter you friends name: ");
	fgets(name,20,stdin);
	int len = strlen(name);
	name[len-1]='\0 ';/*replacing \n with NULL character*/
	int i=0;
	/*writing character by character from index 0 till NULL character*/
	while(name[i]!='\0')
		fputc(name[i++],fp);
	fputc('\n',fp);
	fclose(fp);
	return 0;
}
