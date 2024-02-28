#include <stdio.h>

int max_without_branching(int a, int b) {
    int diff = a - b;
    int mask = diff >> (sizeof(int) * 8 - 1);
    return (b & mask) | (a & ~mask);
}

int main() {
    int a = 10;
    int b = 5;

    printf("Maximum of %d and %d is: %d\n", a, b, max_without_branching(a, b));

    return 0;
}

