#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    fprintf(file, "Appending to the file.\n");
    fclose(file);
    return 0;
}
