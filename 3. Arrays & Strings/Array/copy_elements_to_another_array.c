#include <stdio.h>

int main() {
    int arr1[10];
    int arr2[15];
    int size;
    printf("enter size of array: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
	    printf("Array element %d: ",i+1);
	    scanf("%d",&arr1[i]);
    }
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }

    printf("Elements of arr2 (copied from arr1): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}

