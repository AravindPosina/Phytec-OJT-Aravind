#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    double sum = 0.0;
    int factorial = 1;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }

        sum += (double)factorial / i;

        factorial = 1;
    }
    printf("Sum of the series: %.2f\n", sum);

    return 0;
}

