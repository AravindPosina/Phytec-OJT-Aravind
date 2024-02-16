#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    // Open the input file "input.txt" in read-only mode
    int inputfd = open("input.txt", O_RDONLY);

    if (inputfd == -1) {
        if (errno == ENOENT) {
            // File doesn't exist
            perror("Error: The file 'input.txt' doesn't exist");
        } else {
            // Other error occurred
            perror("Error opening the input file");
        }
        return 1; // Exit with an error code
    }

    // Create the output file "output.txt" in write-only mode
    int outputfd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (outputfd == -1) {
        // Error occurred while creating the output file
        perror("Error creating the output file");
        close(inputfd); // Close the input file
        return 1; // Exit with an error code
    }

    // Initialize a buffer to read and write characters
    char buffer;

    // Read characters from input file and write to output file
    while (read(inputfd, &buffer, sizeof(char)) > 0) {
        write(outputfd, &buffer, sizeof(char));
    }

    // Close both input and output files
    close(inputfd);
    close(outputfd);

    return 0; // Exit with success
}






