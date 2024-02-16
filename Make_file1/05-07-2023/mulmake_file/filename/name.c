#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void name(void)
{
	char sentence[1000];
	FILE *fptr;
	fptr = fopen("program.txt","w");
	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	printf("enter a sentence:\n");
	fgets(sentence , sizeof(sentence) , stdin);
	fprintf(fptr , "%s" , sentence);
	fclose(fptr);
}

