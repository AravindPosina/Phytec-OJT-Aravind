#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fptr;
	char fname[20];
	char ch;
    printf("\n\n Read an existing file :\n");
	printf("------------------------------\n"); 
	printf(" Input the filename to be opened : ");
	scanf("%s",fname);
	fptr = fopen (fname, "r");  
	if (fptr == NULL)
	{
		printf(" File does not exist or cannot be opened.\n");
		exit(1);
	}
	printf("\n The content of the file %s is  :\n",fname);
	ch = fgetc(fptr);
	while (ch != EOF)
		{
			printf ("%c", ch);
			ch = fgetc(fptr);
		}
	fclose(fptr);
    printf("\n\n");
}

