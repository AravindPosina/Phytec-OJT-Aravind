#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("Received SIGINT (Ctrl+C)\n");
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Running... Press Ctrl+C to exit.\n");

    while (1) {
        // Do some work or wait here
    }

    return 0;
}

