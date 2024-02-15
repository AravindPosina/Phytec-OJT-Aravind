#include <stdio.h>

int main() {
    FILE *file = fopen("numbers.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int byte;
    while ((byte = fgetc(file)) != EOF) {
        printf("%02X ", byte);
    }

    fclose(file);

    return 0;
}

