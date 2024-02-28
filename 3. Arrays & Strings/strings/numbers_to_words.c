#include <stdio.h>

// Function to convert a single digit to word
void convertSingleDigit(int digit) {
    switch (digit) {
        case 0:
            printf("Zero ");
            break;
        case 1:
            printf("One ");
            break;
        case 2:
            printf("Two ");
            break;
        case 3:
            printf("Three ");
            break;
        case 4:
            printf("Four ");
            break;
        case 5:
            printf("Five ");
            break;
        case 6:
            printf("Six ");
            break;
        case 7:
            printf("Seven ");
            break;
        case 8:
            printf("Eight ");
            break;
        case 9:
            printf("Nine ");
            break;
        default:
            printf("Invalid digit ");
    }
}

// Function to convert two-digit number to word
void convertTwoDigits(int num) {
    int tens = num / 10;
    int ones = num % 10;

    if (tens == 1) {
        switch (ones) {
            case 0:
                printf("Ten ");
                break;
            case 1:
                printf("Eleven ");
                break;
            case 2:
                printf("Twelve ");
                break;
            case 3:
                printf("Thirteen ");
                break;
            case 4:
                printf("Fourteen ");
                break;
            case 5:
                printf("Fifteen ");
                break;
            case 6:
                printf("Sixteen ");
                break;
            case 7:
                printf("Seventeen ");
                break;
            case 8:
                printf("Eighteen ");
                break;
            case 9:
                printf("Nineteen ");
                break;
        }
    } else {
        switch (tens) {
            case 2:
                printf("Twenty ");
                break;
            case 3:
                printf("Thirty ");
                break;
            case 4:
                printf("Forty ");
                break;
            case 5:
                printf("Fifty ");
                break;
            case 6:
                printf("Sixty ");
                break;
            case 7:
                printf("Seventy ");
                break;
            case 8:
                printf("Eighty ");
                break;
            case 9:
                printf("Ninety ");
                break;
        }
        convertSingleDigit(ones);
    }
}

// Function to convert number to word
void convertToWord(int num) {
    if (num < 0) {
        printf("Minus ");
        num = -num;
    }
    if (num == 0) {
        printf("Zero");
    } else if (num < 10) {
        convertSingleDigit(num);
    } else if (num < 100) {
        convertTwoDigits(num);
    } else if (num < 1000) { // Support three-digit numbers
        int hundreds = num / 100;
        int remaining = num % 100;
        convertSingleDigit(hundreds);
        printf("Hundred ");
        if (remaining != 0) {
            convertTwoDigits(remaining);
        }
    } else {
        printf("Number is out of range");
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    convertToWord(num);
    return 0;
}
