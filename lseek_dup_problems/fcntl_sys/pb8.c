#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
    int fd = open("sample.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Set file for asynchronous I/O
    fcntl(fd, F_SETFL, O_ASYNC);

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while (1) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            perror("read");
            break;
        } else if (bytes_read == 0) {
            printf("End of file.\n");
            break;
        }

        // Process data here
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
    return 0;
}

