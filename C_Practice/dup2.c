#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    // Open a file for demonstration purposes
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Duplicate the file descriptor to a specific new file descriptor (e.g., 3)
    int newfd = 3; // Specify the desired file descriptor number
    int result = dup2(fd, newfd);

    if (result == -1) {
        perror("dup2");
        close(fd); // Close the original file descriptor
        return 1;
    }

    // Check if newfd is equal to the specified value
    if (result == newfd) {
        printf("dup2() succeeded. newfd is %d.\n", newfd);
    } else {
        printf("dup2() failed. newfd is %d.\n", result);
    }

    // Close both original and new file descriptors
    close(fd);
    close(newfd);

    return 0;
}
		
