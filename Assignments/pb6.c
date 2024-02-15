#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Allocate memory for an integer array of size n
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        perror("malloc");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Entered integers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}

