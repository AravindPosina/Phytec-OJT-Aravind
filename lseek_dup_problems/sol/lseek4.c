#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    int source_fd = open("source.txt", O_RDONLY);
    if (source_fd == -1) {
        perror("open source.txt");
        exit(1);
    }

    int dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("open destination.txt");
        close(source_fd);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytesRead) == -1) {
            perror("write");
            close(source_fd);
            close(dest_fd);
            exit(1);
        }
    }

    close(source_fd);
    close(dest_fd);
    return 0;
}

