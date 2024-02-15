#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(1);
    }

    if (pid1 == 0) {  // Child 1
        close(pipe_fd[0]); // Close the read end of the pipe
        dup2(pipe_fd[1], STDOUT_FILENO); // Redirect stdout to the pipe

        // Execute a command whose output will be sent to the pipe
        execlp("ls", "ls", "-l", NULL);
        perror("exec ls");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(1);
    }

    if (pid2 == 0) {  // Child 2
        close(pipe_fd[1]); // Close the write end of the pipe
        dup2(pipe_fd[0], STDIN_FILENO); // Redirect stdin to the pipe

        // Execute a command that reads from stdin (the pipe)
        execlp("sort", "sort", NULL);
        perror("exec sort");
        exit(1);
    }

    // Parent process
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    // Wait for both child processes to finish
    wait(NULL);
    wait(NULL);

    return 0;
}

