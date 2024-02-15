#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int inputFileDescriptor = open("input.txt", O_RDONLY);

    if (inputFileDescriptor == -1) {
        perror("Error opening input file");
        exit(1);
    }

    int outputFileDescriptor = open("output.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);

    if (outputFileDescriptor == -1) {
        perror("Error opening output file");
        exit(1);
    }

    char buffer[1];
    ssize_t bytesRead;

    while ((bytesRead = read(inputFileDescriptor, buffer, sizeof(buffer))) > 0) {
        write(outputFileDescriptor, buffer, bytesRead);
    }

    close(inputFileDescriptor);
    close(outputFileDescriptor);
    return 0;
}

