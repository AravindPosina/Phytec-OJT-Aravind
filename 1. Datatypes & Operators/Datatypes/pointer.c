#include <stdio.h>
int main() {
    int num;
    int *ptr;
    printf("Enter a number: ");
    scanf("%d", &num);
    ptr = &num;
    printf("Value entered: %d\n", *ptr);
    printf("Address of the variable: %p\n", (void *)ptr);
    return 0;
}

