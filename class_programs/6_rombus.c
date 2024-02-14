#include <stdio.h>

int main() {
    int rows = 3;  // Adjust the number of rows as needed
    int i, j, k = 1;

    // Loop for each row (upper half)
    for (i = 1; i <= rows; i++) {
        // Loop for spaces before the numbers
        for (j = i; j < rows; j++) {
            printf("   ");
        }

        // Loop for printing numbers on the left side
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("%2d", k++);
            if (j < 2 * i - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    // Loop for each row (lower half)
    for (i = rows - 1; i >= 1; i--) {
        // Loop for spaces before the numbers
        for (j = rows; j > i; j--) {
            printf("   ");
        }

        // Loop for printing numbers on the right side
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("%2d", k++);
            if (j < 2 * i - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
