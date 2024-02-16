#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    // Open a file for demonstration purposes
    int fd = open("abc.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Set the file descriptor to non-blocking mode using fcntl
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl(F_GETFL)");
        close(fd);
        return 1;
    }

    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl(F_SETFL)");
        close(fd);
        return 1;
    }

    printf("File descriptor %d is now in non-blocking mode.\n", fd);

    // Read from the file descriptor (non-blocking read)
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            printf("No data available for non-blocking read.\n");
        } else {
            perror("read");
        }
    } else {
        buffer[bytesRead] = '\0';
        printf("Read %zd bytes: %s\n", bytesRead, buffer);
    }

    // Close the file descriptor
    close(fd);

    return 0;
}

