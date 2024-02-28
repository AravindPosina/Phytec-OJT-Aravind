#include <stdio.h>

int countWords(char str[]) {
    int words = 0;
    int i = 0;
    
    // Skip leading spaces
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }
    
    // Check for words
    while (str[i] != '\0') {
        // If current character is a space, tab, or newline, it indicates the end of a word
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            // Skip consecutive spaces
            while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
                i++;
            }
            words++;
        } else {
            i++;
        }
    }
    
    // If the last character is not a space, tab, or newline, increment word count
    if (i > 0 && (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n')) {
        words++;
    }
    
    return words;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int words = countWords(str);
    printf("Number of words in the string: %d\n", words);

    return 0;
}

