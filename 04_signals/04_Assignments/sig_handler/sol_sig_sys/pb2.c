#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Child: Received SIGINT (Ctrl+C)\n");
}

int main() {
    pid_t child_pid;

    if ((child_pid = fork()) == 0) {
        // Child process
        signal(SIGINT, sigint_handler);

        printf("Child is running... Press Ctrl+C to exit child.\n");

        while (1) {
            // Child process work
        }
    } else {
        // Parent process
        printf("Parent is running... Child PID: %d\n", child_pid);

        while (1) {
            // Parent process work
        }
    }

    return 0;
}

