#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(char* str){
	char buff[10];
        strcpy(buff,str);
 	//strncpy(buff, str,9);
	printf("The command line received is: %s \n", buff);
}

int main(int argc, char * argv[]){
	if(argc > 1)
		display(argv[1]);
	else
		printf("No command line received.\n");
   	exit(0);
}

