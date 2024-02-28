#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 6, 7, 8, 9, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num_bits = 32; 
    int bitmap = 0;   
    printf("Duplicate elements in the array are: ");
    for (int i = 0; i < size; i++) {
        int mask = 1 << arr[i];
        if (bitmap & mask)  
            printf("%d ", arr[i]);
        else
            bitmap |= mask;     
    }
    printf("\n");
    return 0;
}

