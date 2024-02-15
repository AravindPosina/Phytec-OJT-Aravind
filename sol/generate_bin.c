#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50, 100};
    int numCount = sizeof(numbers) / sizeof(numbers[0]);

    FILE *file = fopen("numbers.bin", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fwrite(numbers, sizeof(int), numCount, file);

    fclose(file);

    return 0;
}

