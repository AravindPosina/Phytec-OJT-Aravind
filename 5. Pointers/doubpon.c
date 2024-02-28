#include <stdio.h>
void doubleNumber(int *ptr) {
    *ptr *= 2;
}

int main() {
    int num = 10;
    int *ptr = &num;

    printf("Before doubling: %d\n", num);
    doubleNumber(ptr);

    printf("After doubling: %d\n", num);

    return 0;
}

