#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("sample.txt", O_RDWR | O_APPEND);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Get and print file descriptor flags
    int fd_flags = fcntl(fd, F_GETFL, 0);
    printf("File Descriptor Flags:\n");
    printf("O_RDONLY: %s\n", (fd_flags & O_RDONLY) ? "Yes" : "No");
    printf("O_WRONLY: %s\n", (fd_flags & O_WRONLY) ? "Yes" : "No");
    printf("O_RDWR: %s\n", (fd_flags & O_RDWR) ? "Yes" : "No");
    printf("O_APPEND: %s\n", (fd_flags & O_APPEND) ? "Yes" : "No");
    printf("O_NONBLOCK: %s\n", (fd_flags & O_NONBLOCK) ? "Yes" : "No");
    printf("\n");

    // Get and print file status flags
    int fs_flags = fcntl(fd, F_GETFD, 0);
    printf("File Status Flags:\n");
    printf("FD_CLOEXEC: %s\n", (fs_flags & FD_CLOEXEC) ? "Yes" : "No");

    close(fd);
    return 0;
}

