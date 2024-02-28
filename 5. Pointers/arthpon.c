#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; 

    printf("Element at index 0: %d\n", *ptr);
    printf("Element at index 1: %d\n", *(ptr + 1)); 
    printf("Element at index 2: %d\n", *(ptr + 2)); 

    return 0;
}

