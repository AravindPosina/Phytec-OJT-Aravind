#include <stdio.h>

void factorial(int n, int *result) {
    *result = 1;
    for (int i = 1; i <= n; i++) {
        *result *= i;
    }
}

int main() {
    int num = 5;
    int fact;
    factorial(num, &fact);

    printf("Factorial of %d: %d\n", num, fact);

    return 0;
}

