#include <stdio.h>

int main() {
    FILE *source = fopen("example.txt", "r");
    FILE *destination = fopen("destination.txt", "w");
    if (source == NULL || destination == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), source) != NULL) {
        fprintf(destination, "%s", buffer);
    }
    fclose(source);
    fclose(destination);
    return 0;
}
