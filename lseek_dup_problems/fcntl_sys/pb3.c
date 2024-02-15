#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int fd = open("sample.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Set non-blocking mode
    int flags = fcntl(fd, F_GETFL, 0);
    flags |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flags);

    char buffer[128];
    int bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        // Process data here
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    if (bytesRead == -1 && errno == EAGAIN) {
        printf("No data available.\n");
    }

    close(fd);
    return 0;
}

