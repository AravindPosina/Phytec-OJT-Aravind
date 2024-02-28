#include <stdio.h>

void modify(int *ptr) {
    *ptr = 100;
}

int main() {
    int num = 10;

    printf("Before modification: num = %d\n", num);

    modify(&num); 

    printf("After modification: num = %d\n", num);

    return 0;
}

