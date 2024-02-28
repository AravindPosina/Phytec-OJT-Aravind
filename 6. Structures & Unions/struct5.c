#include <stdio.h>

union Number {
    int integer;
    float floating;
};

int main() {
    union Number num;
    num.integer = 42;

    printf("Integer value: %d\n", num.integer);

    num.floating = 3.14;
    printf("Floating-point value: %f\n", num.floating);

    return 0;
}

