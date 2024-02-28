#include <stdio.h>

int main() {
    int *ptr = 0;

    printf("Pointer value: %p\n", &ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    return 0;
}

