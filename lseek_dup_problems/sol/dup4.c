#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file_fd = open("input.txt", O_RDONLY);
    if (file_fd == -1) {
        perror("open input.txt");
        exit(1);
    }

    int stdin_copy = dup(STDIN_FILENO); // Duplicate stdin

    if (dup2(file_fd, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }

    char buffer[256];
    ssize_t bytesRead;

    // Now, anything read from stdin will come from input.txt
    bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("read");
        exit(1);
    }

    printf("Read from input.txt: %.*s\n", (int)bytesRead, buffer);

    // Restore stdin to its original state
    if (dup2(stdin_copy, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }

    close(file_fd);
    return 0;
}

