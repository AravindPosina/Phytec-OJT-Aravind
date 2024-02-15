#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int result;

    result = kill(9999, SIGUSR1);  // Try to send SIGUSR1 to non-existent process

    if (result == -1) {
        if (errno == ESRCH) {
            printf("Error: Process not found.\n");
        } else {
            perror("Error sending signal");
        }
    }

    return 0;
}

