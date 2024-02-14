#include<stdio.h>
#include"arr.h"
int main() {
	int A[5]={11,35,45,56,90};
	printf("size of the array = %ld\n",sizeof(A));
	for(int i=0;i<5;i++) 
	{
		printf("%d\n",A[i]);
	}
}
