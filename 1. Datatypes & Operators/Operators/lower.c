#include <stdio.h>
char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        c &= ~(1 << 5);
    }
    return c;
}
int main() {
    char c;
    printf("Enter a lowercase character: ");
    scanf("%c", &c);
    c = toUpper(c);
    printf("Uppercase equivalent: %c\n", c);
    return 0;
}

