#include <stdio.h>

int main() {
    int arr[14],i,size;
    printf("enter size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	    printf("Array element %d: ",i+1);
	    scanf("%d",&arr[i]);
    }
    int min = arr[0]; // Assume first element as the minimum

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Smallest element in the array: %d\n", min);

    return 0;
}

