#include <stdio.h>

int main() {
    char string[100];
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    printf("You entered: %s\n", string);
    return 0;
}

