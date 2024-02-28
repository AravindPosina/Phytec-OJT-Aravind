#include <stdio.h>

void stringConcat(char *dest, const char *src) {
  
    while (*dest != '\0') {
        dest++;
    }
    
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    
    *dest = '\0';
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%[^\n]", str1);
    printf("Enter the second string: ");
    scanf(" %[^\n]", str2);  // Note the space before %[^\n]
    char *ptr = str1;
    stringConcat(ptr, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}

