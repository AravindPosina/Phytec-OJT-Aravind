#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum) {
    printf("Received SIGUSR1\n");
}

int main() {
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);

    // Block SIGUSR1
    sigprocmask(SIG_BLOCK, &mask, NULL);

    printf("Blocking SIGUSR1... Send SIGUSR1 to unblock.\n");

    while (1) {
        // Do some work or wait here
    }

    return 0;
}

