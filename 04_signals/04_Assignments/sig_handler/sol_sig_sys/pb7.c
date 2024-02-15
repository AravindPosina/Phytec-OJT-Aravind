#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t interrupted = 0;

void sigint_handler(int signum) {
    interrupted = 1;
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Running... Press Ctrl+C to exit gracefully.\n");

    while (!interrupted) {
        // Do some work or wait here
    }

    printf("Exiting gracefully.\n");
    return 0;
}

