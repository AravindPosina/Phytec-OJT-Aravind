#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    char *shmaddr;
    key_t key = ftok(".", 'S'); // Generate a unique key for shared memory

    // Create or access a shared memory segment
    shmid = shmget(key, 100, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment to the process's address space
    shmaddr = (char *)shmat(shmid, NULL, 0);

    if (shmaddr == (char *)(-1)) {
        perror("shmat");
        return 1;
    }

    // Write a message to shared memory
    strcpy(shmaddr, "Hello, shared memory!");

    // Detach shared memory from the process
    shmdt(shmaddr);

    // Create another process (fork)
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        // Child process reads and prints the message from shared memory
        shmaddr = (char *)shmat(shmid, NULL, 0);

        if (shmaddr == (char *)(-1)) {
            perror("shmat (child)");
            return 1;
        }

        printf("Child process received message: %s\n", shmaddr);

        // Detach shared memory from the child process
        shmdt(shmaddr);
    }

    // The parent process waits for the child to finish
    wait(NULL);

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

