#include <stdio.h>

int main() {
    int num;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check the least significant bit (LSB) of the number
    // If the LSB is 0, the number is even
    if ((num & 1) == 0) {
        printf("%d is an even number.\n", num);
    }
    else
    {
	    printf("%d is not even number .\n", num);
    }

    return 0;
}

