#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("file_to_truncate.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    off_t newFileSize;
    printf("Enter the new size of the file: ");
    scanf("%lld", &newFileSize);

    if (lseek(fd, newFileSize, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        exit(1);
    }

    if (ftruncate(fd, newFileSize) == -1) {
        perror("ftruncate");
        close(fd);
        exit(1);
    }

    close(fd);
    return 0;
}

