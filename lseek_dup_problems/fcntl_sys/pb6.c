#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define RECORD_SIZE 100

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

    int record_number = 1;  // Adjust as needed

    struct flock lock;
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = record_number * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    // Lock acquired, work with the specific record
    printf("Record %d locked. Press Enter to unlock...\n", record_number);
    getchar();  // Wait for user input

    lock.l_type = F_UNLCK;  // Unlock
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
    }

    close(fd);
    return 0;
}

