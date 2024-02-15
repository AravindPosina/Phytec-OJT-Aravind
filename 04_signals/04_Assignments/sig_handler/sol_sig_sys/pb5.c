#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum) {
    printf("Received SIGUSR1 from the other process\n");
}

int main() {
    pid_t child_pid;

    if ((child_pid = fork()) == 0) {
        // Child process
        signal(SIGUSR1, sigusr1_handler);

        printf("Child is running... Waiting for SIGUSR1 from the parent.\n");

        while (1) {
            // Child process work
        }
    } else {
        // Parent process
        printf("Parent is running... Sending SIGUSR1 to the child.\n");

        sleep(2);  // Give child time to set up signal handler

        // Send SIGUSR1 to the child
        kill(child_pid, SIGUSR1);

        while (1) {
            // Parent process work
        }
    }

    return 0;
}

