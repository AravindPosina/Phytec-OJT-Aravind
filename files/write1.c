#include <stdio.h>

int main() {
    FILE *file;
    char data[] = "Hello, fwrite!\n";

    // Open a file for writing
    file = fopen("example.txt", "wb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    // Write data to the file using fwrite
    size_t element_size = sizeof(char);
    size_t elements_written = fwrite(data, element_size, sizeof(data) / element_size, file);

    if (elements_written != sizeof(data) / element_size) {
        perror("fwrite");
        fclose(file);
        return 1;
    }

    printf("Successfully wrote %zu elements to the file.\n", elements_written);

    // Close the file
    fclose(file);

    return 0;
}

