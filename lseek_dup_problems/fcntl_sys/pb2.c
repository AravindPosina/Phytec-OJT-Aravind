#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1 = open("sample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd1 == -1) {
        perror("open");
        exit(1);
    }

    int fd2 = fcntl(fd1, F_DUPFD, 0);

    write(fd1, "Hello, ", 7);
    write(fd2, "world!\n", 7);

    close(fd1);
    close(fd2);

    return 0;
}

