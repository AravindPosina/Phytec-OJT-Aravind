#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Received SIGINT (Ctrl+C)\n");
}

void sigterm_handler(int signum) {
    printf("Received SIGTERM\n");
}

void sigusr1_handler(int signum) {
    printf("Received SIGUSR1\n");
}

void sigusr2_handler(int signum) {
    printf("Received SIGUSR2\n");
}

int main() {
    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    printf("Running... Press Ctrl+C, send SIGTERM, SIGUSR1, or SIGUSR2 to test.\n");

    while (1) {
        // Do some work or wait here
    }

    return 0;
}

