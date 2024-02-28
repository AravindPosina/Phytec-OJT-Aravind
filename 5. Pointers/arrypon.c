#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("Array elements using array notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Array elements using pointer notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i)); 
    }
    printf("\n");

    return 0;
}

