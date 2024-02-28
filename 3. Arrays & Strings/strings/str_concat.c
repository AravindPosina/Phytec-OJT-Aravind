#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];

    // Input two strings from user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters from input
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Concatenate str2 to str1
    strcat(str1, str2);

    // Print the concatenated string
    printf("Concatenated string: %s\n", str1);

    return 0;
}

