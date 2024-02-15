I'll provide solutions to the exercise problems related to system calls used for memory management.

**Problem 1: Memory Allocation**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Allocate memory for an integer array of size n
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum of the entered integers: %d\n", sum);

    // Free the allocated memory
    free(arr);

    return 0;
}
```

**Problem 2: Dynamic Array Resizing**

```c
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
```

Please note that in a real-world application, you should also handle potential errors and edge cases, such as failed memory allocation or reallocation, to ensure robustness.

I'll provide solutions for the remaining problems in subsequent responses to avoid excessive length in a single response.
