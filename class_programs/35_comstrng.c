#include <stdio.h>
#include <string.h>

int main() {
    char inputString[20];
    printf("Enter a string: ");
    scanf("%s", inputString);

    int length = strlen(inputString);

    char combination[20];
    int index = 0;

    for (int start = 0; start < length; start++) {
        for (int i = start; i < length; i++) {
            combination[index++] = inputString[i];
            combination[index] = '\0'; 
            printf("%s\n", combination);
        }

        index = 0; 
    }

    return 0;
}

