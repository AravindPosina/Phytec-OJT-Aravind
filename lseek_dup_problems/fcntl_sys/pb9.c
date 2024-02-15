#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("sample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Create a child process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        // This is the child process

        // Close the standard output (file descriptor 1)
        close(1);

        // Duplicate the file descriptor fd to the standard output
        dup(fd);

        // Now, anything written to stdout will go to the file
        printf("This will be written to the file.\n");

        // Close the duplicated file descriptor
        close(fd);
    } else {
        // This is the parent process

        // Wait for the child process to finish
        wait(NULL);

        // Close the original file descriptor
        close(fd);
    }

    return 0;
}

