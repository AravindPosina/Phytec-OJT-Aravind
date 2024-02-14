#include<stdio.h>
#include<malloc.h>
display_DMA() {
	int size;
	int *ptr;
	printf("Enter the size \n");
	scanf("%d",&size);
	ptr=malloc(size*sizeof(int));
	printf("Enter %d numbers:\n",size);
	int max=maximum(ptr,size);
}
