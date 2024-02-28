#include <stdio.h>

void add(int a, int b) {
    printf("Sum: %d\n", a + b);
}

void subtract(int a, int b) {
    printf("Difference: %d\n", a - b);
}

void performOperation(void (*operation)(int, int), int a, int b) {
    operation(a, b);
}

int main() {
    performOperation(&add, 10, 5); // Passing add function pointer
    performOperation(&subtract, 10, 5); // Passing subtract function pointer

    return 0;
}

