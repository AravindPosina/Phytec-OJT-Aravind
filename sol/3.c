#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fileDescriptor = open("numbers.bin", O_RDONLY);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        exit(1);
    }

    int number;
    int sum = 0;
    ssize_t bytesRead;

    while ((bytesRead = read(fileDescriptor, &number, sizeof(int))) > 0) {
        sum += number;
    }

    printf("Sum: %d\n", sum);

    close(fileDescriptor);
    return 0;
}

