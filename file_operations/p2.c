/*The program reads from the file line by line and displays the
data read on the screen*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	//checking if file name given or not

	if(argc!=2)
	{ 
		printf("Invalid number of arguments entered.\
		Please enter filename to display its contents....\n");
		exit(1);
	}
	
	/*passing argv[1] for the file name, 
         * as user will pass file name in it, and opening the file
         * in read only mode*/

	FILE* fp=fopen(argv[1],"r");


	if(fp==NULL)
	{
		perror("fopen() failed\n");exit(1);
	}

	char buff[512];

	/*reading from file line by line till EOF */

	while(fgets(buff,512,fp)!=NULL) 
		fputs(buff,stdout);/*printing line by line on stdout , 
				     could also be done using puts(buff);*/
	fclose(fp); //closing the file
	return 0;
}
