#include <stdio.h>

int min_without_branching(int a, int b) {
    int diff = a - b;
    int mask = diff >> (sizeof(int) * 8 - 1);
    return (a & mask) | (b & ~mask);
}

int main() {
    int a = 10;
    int b = 5;

    printf("Minimum of %d and %d is: %d\n", a, b, min_without_branching(a, b));

    return 0;
}

