#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, count = 0;
    printf("Enter number: ");
    scanf("%d", &num);

    int *factors = (int*)malloc(num * sizeof(int));
    if (factors == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            factors[count++] = i;
        }
    }

    if (count > 0) {
        printf("The number is not prime, factors are: ");
        for (i = 0; i < count; i++) {
            printf("%d ", factors[i]);
        }
    } else {
        printf("The number is prime");
    }

 
    free(factors);

    return 0;
}

