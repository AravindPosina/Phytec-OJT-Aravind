#include<stdio.h>
#include <stdio.h>

void add(int a, int b) {
    printf("Sum: %d\n", a + b);
}

void subtract(int a, int b) {
    printf("Difference: %d\n", a - b);
}

int main() {

    void (*operation)(int, int);
    operation = &add;
    operation(10, 5);
    operation = &subtract;
    operation(10, 5);

    return 0;
}

