/*The program reads from file character by character till EOF and
displays it on stdout */

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	//checking if file name given or not
	if(argc!=2)
	{                
		printf("Invalid number of arguments entered\
			    	enter filename to display its contents....\n");
		exit(1);
	}
	/*passing argv[1] for the file name,
         *as user will pass file name in it,
         *and opening the file in read only mode*/
	FILE* fp=fopen(argv[1],"r");

	if(fp==NULL)//checking if the file has opened or not
	{ 	
		perror("fopen() failed\n");exit(1);
	}
	int c;
	/*reading from file character by character till EOF */
	while((c=fgetc(fp))!=EOF)
        	putc(c,stdout); /*printing character by character on 
		                  stdout , could also be done using putc(c); */
	fclose(fp);
	return 0;
}
