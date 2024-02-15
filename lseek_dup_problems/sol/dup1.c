#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (file_fd == -1) {
        perror("open output.txt");
        exit(1);
    }

    int stdout_copy = dup(STDOUT_FILENO); // Duplicate stdout

    if (dup2(file_fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }

    // Now, anything written to stdout will be redirected to output.txt
    printf("This will be written to output.txt\n");

    // Restore stdout to its original state
    if (dup2(stdout_copy, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }

    close(file_fd);
    return 0;
}

