/*Program takes a string from user and writes it to a file line by
line*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("Invalid number of arguments entered. Please\
			enter filename to display its contents....\n");
		exit(1);
	}
	FILE* fp=fopen(argv[1],"a"); //opening in append mode

	if(fp==NULL)
	{
		perror("fopen() failed\n");
		exit(1);
	}

	char name[20];
	printf("Enter you friends name: ");
 
      /*taking input using scanf (), it will automatically place \0 at the end*/
	scanf("%[^\n]s",name);
	fputs(name,fp);//writing the complete name
	fputc('\n',fp);
	printf("Done..Bye..Bye..\n");
	fclose(fp);
	return 0;
}
