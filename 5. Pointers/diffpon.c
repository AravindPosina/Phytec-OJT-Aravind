#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = &arr[1]; 
    int *ptr2 = &arr[4];
    int diff = ptr2 - ptr1;

    printf("Difference between pointers: %d\n", diff);

    return 0;
}

