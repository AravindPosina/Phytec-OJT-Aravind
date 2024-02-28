#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *start = arr;
    int *end = arr + 4; 
    while (start < end) {
        
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    printf("Reversed array elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

