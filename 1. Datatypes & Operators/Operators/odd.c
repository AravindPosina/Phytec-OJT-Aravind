#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num & 1) {
        printf("%d is an odd number.\n", num);
    } else {
        printf("%d is not an odd number.\n", num);
    }
    return 0;
}

