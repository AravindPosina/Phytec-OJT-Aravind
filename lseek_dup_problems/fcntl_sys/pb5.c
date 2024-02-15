#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

void handle_timeout(int signo) {
    if (signo == SIGALRM) {
        printf("Lock attempt timed out.\n");
        exit(0);
    }
}

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
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    // Set up a signal handler for the timeout
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_timeout;
    sigaction(SIGALRM, &sa, NULL);

    // Set an alarm for a timeout of 10 seconds
    alarm(10);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        if (errno == EINTR) {
            printf("Lock interrupted.\n");
        } else {
            perror("fcntl");
        }
        close(fd);
        exit(1);
    }

    // Lock acquired, do some work
    printf("File locked. Press Enter to unlock...\n");
    getchar();  // Wait for user input

    lock.l_type = F_UNLCK;  // Unlock
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
    }

    close(fd);
    return 0;
}

