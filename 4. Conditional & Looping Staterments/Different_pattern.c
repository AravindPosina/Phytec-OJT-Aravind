#include <stdio.h>

int main() {
    int n = 5;
    int spaces = n - 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf("   ");
        }

        for (int j = i; j < i + i; j++) {
            printf("%2d ", j);
        }

        for (int j = i + i - 2; j >= i; j--) {
            printf("%2d ", j);
        }
        printf("\n");
        spaces--;
    }

    return 0;
}
