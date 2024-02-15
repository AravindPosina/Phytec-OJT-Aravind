#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    int fd_copy = dup(fd); // Duplicate the file descriptor

    close(fd); // Close the original file descriptor

    char buffer[256];
    ssize_t bytesRead;

    bytesRead = read(fd_copy, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("read");
        close(fd_copy);
        exit(1);
    }

    printf("Read from duplicated file descriptor: %.*s\n", (int)bytesRead, buffer);

    close(fd_copy);
    return 0;
}

