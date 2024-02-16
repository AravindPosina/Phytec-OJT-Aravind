#include <stdio.h>

int main() {
    int decimalNumber;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Toggle the 2nd bit
    int toggledNumber = decimalNumber ^ (1 << 1);

    // Display the result in binary
    printf("Original binary: ");
    printBinary(decimalNumber);

    printf("Toggled binary : ");
    printBinary(toggledNumber);

    return 0;
}

// Function to print binary representation of a number
void printBinary(int num) {
    int bits[sizeof(int) * 8];  // Assuming an int is 32 bits

    // Convert decimal to binary
    for (int i = 0; i < sizeof(int) * 8; i++) {
        bits[i] = num % 2;
        num = num / 2;
    }

    // Print binary representation in reverse order
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }

    printf("\n");
}

