#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t ready = 0;

void sigusr1_handler(int signum) {
    ready = 1;
}

int main() {
    signal(SIGUSR1, sigusr1_handler);

    pid_t child_pid;

    if ((child_pid = fork()) == 0) {
        // Child process
        printf("Child: Waiting for a signal to proceed.\n");

        while (!ready) {
            // Waiting for the signal
        }

        printf("Child: Received signal, proceeding...\n");
        // Continue with child process tasks

        exit(0);
    } else {
        // Parent process
        printf("Parent: Sending a signal to the child to synchronize.\n");
        sleep(1);  // Give child time to set up signal handler

        kill(child_pid, SIGUSR1);

        wait(NULL);
    }

    return 0;
}

