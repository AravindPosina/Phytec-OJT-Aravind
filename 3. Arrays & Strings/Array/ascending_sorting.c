#include <stdio.h>

int main() {
    int arr[10];
    int size,i;
    printf("enter size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	    printf("Array element %d: ",i+1);
	    scanf("%d",&arr[i]);
    }

    for ( i = 0; i < size-1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array sorted in ascending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

