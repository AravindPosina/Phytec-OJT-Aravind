/*The program reads from a file using formatted functions*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("Invalid number of arguments entered.\
			Please enter filename to display its contents....\n");
		exit(1);
	}
	FILE* fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		perror("fopen() failed\n");exit(1);
	}
	int n;

	
	/*Here integer will be read from fp and stored in n*/
	fscanf(fp,"%d, ",&n);
	while(feof(fp)==0)
	{
		fprintf(stdout,"%d ",n);
		fscanf(fp,"%d, ",&n);

		/*comma after %d indicates that read till a 
		 *comma too, integers, by default, are read 
		 until a space, tab or newline character occurs, 
		 here comma is specified because the numbers 
		 may be comma separated*/
         }
         printf("\n");
         fclose(fp);
         return 0;
}
