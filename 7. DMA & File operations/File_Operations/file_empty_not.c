#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    fseek(file, 0, SEEK_END); 
    if (ftell(file) == 0) {
        printf("File is empty.\n");
    } else {
        printf("File is not empty.\n");
    }
    fclose(file);
    return 0;
}
