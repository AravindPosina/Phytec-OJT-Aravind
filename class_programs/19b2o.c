#include <stdio.h>

int main() {
    long long binaryNumber;
    int octalNumber = 0, decimalNumber = 0, base = 1;

    // Input binary number from user
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);

    // Convert binary to decimal
    while (binaryNumber != 0) {
        decimalNumber += (binaryNumber % 10) * base;
        binaryNumber /= 10;
        base *= 2;
    }

    // Convert decimal to octal
    base = 1;
    while (decimalNumber != 0) {
        octalNumber += (decimalNumber % 8) * base;
        decimalNumber /= 8;
        base *= 10;
    }

    // Display the octal number
    printf("Octal equivalent: %d\n", octalNumber);

    return 0;
}
