#include <stdio.h>

struct Flags {
    unsigned int isSetA : 1;
    unsigned int isSetB : 1;
    unsigned int isSetC : 1;
};

int main() {
    struct Flags flags = {1, 0, 1};

    printf("Flag A: %d\n", flags.isSetA);
    printf("Flag B: %d\n", flags.isSetB);
    printf("Flag C: %d\n", flags.isSetC);

    return 0;
}

