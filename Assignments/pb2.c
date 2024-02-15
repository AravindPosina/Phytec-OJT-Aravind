#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int n = 0;
    int size = 1; // Initial size of the array
    int num;

    while (1) {
        printf("Enter an integer (0 to stop): ");
        scanf("%d", &num);

        if (num == 0)
            break;

        if (n >= size) {
            size *= 2;
            arr = (int *)realloc(arr, size * sizeof(int));

            if (arr == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }
        }

        arr[n] = num;
        n++;
    }

    printf("Entered elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}

