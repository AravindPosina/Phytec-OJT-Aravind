#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main() {
    // Open the file "numbers.bin" in read-only mode
    int fd = open("numbers.bin", O_RDONLY);

    if (fd == -1) {
        if (errno == ENOENT) {
            // File doesn't exist
            perror("Error: The file 'numbers.bin' doesn't exist");
        } else {
            // Other error occurred
            perror("Error opening the file");
        }
        return 1; // Exit with an error code
    }

    // Initialize variables for reading and computing the sum
    int sum = 0;
    int num;

    // Read integers from the file and compute their sum
    while (read(fd, &num, sizeof(int)) > 0) {
        sum += num;
    }

    // Close the file
    close(fd);

    // Display the sum
    printf("Sum of numbers: %d\n", sum);

    return 0; // Exit with success
}
