#include <stdio.h>
#include <stdlib.h> 

int *Reverse(int num);

int *Reverse(int num) {
    int rem = 0, res;
    int num1 = num;
    
 
    int *reversed = (int *)malloc(sizeof(int));
    if (reversed == NULL) {
        printf("Memory allocation failed\n");
        return NULL; 
    }

    while (num) {
        res = num % 10;
        rem = rem * 10 + res;
        num = num / 10;
    }

    *reversed = rem;
    return reversed;
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    int *reversed = Reverse(num);

    if (reversed != NULL) {
        printf("Reversed number: %d\n", *reversed);

        free(reversed);
    }

    return 0;
}

