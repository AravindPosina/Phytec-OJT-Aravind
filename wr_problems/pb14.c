#include <stdio.h>
#include <stdlib.h>

void main()
{
	char ch, fname[20];
	FILE *fpts, *fptt;
	
	printf("\n\n Decrypt a text file :\n");
	printf("--------------------------\n"); 	
	
	printf(" Input the name of file to decrypt : ");
	scanf("%s",fname);	
	
	fpts=fopen(fname, "w");
	if(fpts==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		exit(7);
	}
	fptt=fopen("temp.txt", "r");
	if(fptt==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		fclose(fpts);
		exit(9);
	}
	while(1)
	{
		ch=fgetc(fptt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-100;
			fputc(ch, fpts);
		}
	}
	printf(" The file %s decrypted successfully..!!\n\n",fname);
	fclose(fpts);
	fclose(fptt);
}

