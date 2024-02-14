#include <stdio.h>

void decimalToHexadecimal(int decimalNumber) {
    char hexadecimalNumber[100];
    int index = 0;

    // Loop to convert decimal to hexadecimal
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;

        if (remainder < 10) {
            hexadecimalNumber[index] = remainder + '0';
        } else {
            hexadecimalNumber[index] = remainder - 10 + 'A';
        }

        decimalNumber /= 16;
        index++;
    }

    // Print the hexadecimal number in reverse order
    printf("Hexadecimal Equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimalNumber[i]);
    }

    printf("\n");
}

int main() {
    int decimalNumber;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Call the function to convert and print hexadecimal equivalent
    decimalToHexadecimal(decimalNumber);

    return 0;
}

