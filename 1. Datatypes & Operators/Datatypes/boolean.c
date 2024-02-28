#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int booleanVar = (n != 0);
    printf("Boolean Value: %s\n", booleanVar ? "true" : "false");
    
    return 0;
}

