#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigterm_handler(int signum) {
    printf("Received SIGTERM, but ignoring it for 5 seconds.\n");
    sleep(5);
    printf("Done ignoring SIGTERM.\n");
}

int main() {
    signal(SIGTERM, sigterm_handler);

    printf("Running... Send SIGTERM to terminate.\n");

    while (1) {
        // Do some work or wait here
    }

    return 0;
}

