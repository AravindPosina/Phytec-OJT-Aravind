#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigrtmin1_handler(int signum) {
    printf("Received SIGRTMIN+1\n");
}

void sigrtmin2_handler(int signum) {
    printf("Received SIGRTMIN+2\n");
}

int main() {
    signal(SIGRTMIN+1, sigrtmin1_handler);
    signal(SIGRTMIN+2, sigrtmin2_handler);

    printf("Running... Send SIGRTMIN+1 or SIGRTMIN+2 to test.\n");

    while (1) {
        // Do some work or wait here
    }

    return 0;
}

