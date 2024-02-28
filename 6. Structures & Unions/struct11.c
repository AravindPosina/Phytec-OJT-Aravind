#include <stdio.h>

union Value {
    int integerValue;
    float floatValue;
};

int main() {
    union Value values[5];

    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0) {
            values[i].integerValue = i * 2;
            printf("Integer Value: %d\n", values[i].integerValue);
        } else {
            values[i].floatValue = i * 1.5;
            printf("Float Value: %f\n", values[i].floatValue);
        }
    }

    return 0;
}

