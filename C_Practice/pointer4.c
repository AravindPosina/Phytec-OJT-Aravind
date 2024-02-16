#include<stdio.h>

int *larger(int *, int *);

int main() {
    int a = 10, b = 15;
    int *greater;
    greater = larger(&a, &b);
    printf("Larger value = %d", *greater);
    return 0;
}

int *larger(int *a, int *b) {
    if (*a > *b) {
        return a;
    }
    return b;
}
