#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signo) {
    printf("Received SIGUSR1 signal\n");
}

int main() {
    signal(SIGUSR1, sigusr1_handler);

    printf("Waiting for SIGUSR1 signal...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}

