#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    if (kill(pid, SIGUSR1) == -1) {
        perror("kill");
        return 1;
    }

    printf("Sent SIGUSR1 to process %d\n", pid);
    return 0;
}

