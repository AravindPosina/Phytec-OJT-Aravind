#include"stdio.h"
int main() {
	char inputstring[100];
	printf("Enter a string: ");
	gets(inputstring);
	splitwordsBycomma(inputstring);
	return 0;
}

