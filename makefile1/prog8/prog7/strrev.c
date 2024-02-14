#include<stdio.h>
int main() {
	char a[20]="Python programming";
	char *ptr;
	ptr=a;
	mystrrev(ptr);
	printf("%s",ptr);
	printf("\n");
	return 0;
}
