#include<stdio.h>
#include<string.h>
void splitwordsBycomma(char*inputstring) {
	int length=strlen(inputstring);
	int i;
	for(i=0;i<length;i++) {
		if(inputstring[i]==' ')
		{
			inputstring[i]=',';
		}
	}
	printf("splitwords : %s\n",inputstring);
}
