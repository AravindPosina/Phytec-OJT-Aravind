#include <stdio.h>

int main() {
    int n;
    printf("Enter the pattern length: ");
    scanf("%d", &n);

    int sequence[n];
    sequence[0] = 1;

    for (int i = 1; i < n; i++) {
        if (sequence[i - 1] % 2 == 1) {
            sequence[i] = sequence[i - 1] * 2;
        } else {
            sequence[i] = sequence[i - 1] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    return 0;
}

