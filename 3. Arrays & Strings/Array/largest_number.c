#include <stdio.h>

int main() {
    int arr[14],size,i;
    printf("enter size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	    printf("Array element %d : ",i+1);
	    scanf("%d",&arr[i]);
    }
    
    int max = arr[0]; // Assume first element as the maximum

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Largest element in the array: %d\n", max);

    return 0;
}

