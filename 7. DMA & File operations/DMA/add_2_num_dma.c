#include <stdio.h>
#include <stdlib.h>

int main() {
    int *num1, *num2, sum;

    num1 = (int *)malloc(sizeof(int));
    num2 = (int *)malloc(sizeof(int));

    if (num1 == NULL || num2 == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }


    printf("Enter first number: ");
    scanf("%d", num1);

    printf("Enter second number: ");
    scanf("%d", num2);

    sum = *num1 + *num2;

    printf("Sum of %d and %d is %d\n", *num1, *num2, sum);

    free(num1);
    free(num2);

    return 0;
}

