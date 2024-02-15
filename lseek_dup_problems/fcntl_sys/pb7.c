#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    struct flock lock;
    lock.l_type = F_WRLCK;  // Test for write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_GETLK, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    if (lock.l_type == F_UNLCK) {
        printf("File is not locked by another process.\n");
    } else {
        printf("File is locked by another process.\n");
        printf("PID of locking process: %d\n", lock.l_pid);
    }

    close(fd);
    return 0;
}

