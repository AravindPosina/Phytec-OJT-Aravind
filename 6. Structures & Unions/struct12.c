#include <stdio.h>

struct MathOperations {
    int (*add)(int, int);
    int (*subtract)(int, int);
};

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    struct MathOperations mathOps = {add, subtract};

    int resultAdd = mathOps.add(5, 3);
    int resultSubtract = mathOps.subtract(8, 4);

    printf("Addition Result: %d\n", resultAdd);
    printf("Subtraction Result: %d\n", resultSubtract);

    return 0;
}

