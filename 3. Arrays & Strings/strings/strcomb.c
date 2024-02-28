#include <stdio.h>
#include <string.h>

int main() {
    char inputString[20];  // Assuming a maximum length of 20 for the input string

    // Get input from the user
    printf("Enter a string: ");
    scanf("%s", inputString);

    int length = strlen(inputString);

    char combination[20];  // Assuming a maximum length of 20 for the string
    int index = 0;

    for (int start = 0; start < length; start++) {
        for (int i = start; i < length; i++) {
            combination[index++] = inputString[i];
            combination[index] = '\0';  // Null-terminate the string
            printf("%s\n", combination);
        }

        index = 0;  // Reset index for the next iteration
    }

    return 0;
}
