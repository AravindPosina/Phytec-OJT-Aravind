#include <stdio.h>
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        c |= (1 << 5);
    }
    return c;
}
int main() {
    char c;
    printf("Enter an uppercase character: ");
    scanf("%c", &c);
    c = toLower(c);
    printf("Lowercase equivalent: %c\n", c);
    return 0;
}

