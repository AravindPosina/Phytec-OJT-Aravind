#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("sample.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    off_t pos = lseek(fd, -100, SEEK_END);
    if (pos == -1) {
        perror("lseek");
        close(fd);
        exit(1);
    }

    char buffer[101];
    ssize_t bytesRead = read(fd, buffer, 100);
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    buffer[bytesRead] = '\0';
    printf("Last 100 bytes: %s\n", buffer);

    close(fd);
    return 0;
}

