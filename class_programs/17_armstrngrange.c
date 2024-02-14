#include <stdio.h>
#include <math.h>

int main() {
    int lowerLimit, upperLimit;

    printf("Enter the lower limit: ");
    scanf("%d", &lowerLimit);

    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);

    printf("Armstrong numbers between %d and %d are:\n", lowerLimit, upperLimit);

    for (int i = lowerLimit; i <= upperLimit; ++i) {
        int originalNumber = i;
        int n = 0;
        int result = 0;
        
        while (originalNumber != 0) {
            originalNumber /= 10;
            ++n;
        }

        originalNumber = i;

        while (originalNumber != 0) {
            int remainder = originalNumber % 10;
            result += pow(remainder, n);
            originalNumber /= 10;
        }

        if (result == i) {
            printf("%d\n", i);
        }
    }

    return 0;
}

