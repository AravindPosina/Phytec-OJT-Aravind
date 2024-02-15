#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>

int main() {
    int size = 1024 * 1024 * 100; // Allocate 100 MB of memory
    char *data;

    // Allocate memory
    data = (char *)malloc(size);

    if (data == NULL) {
        perror("malloc");
        return 1;
    }

    // Initialize the memory
    memset(data, 'A', size);

    // Lock the memory
    if (mlock(data, size) != 0) {
        perror("mlock");
        free(data);
        return 1;
    }

    // Perform some operations on the locked memory
    // For demonstration purposes, we'll just sleep for a few seconds
    printf("Sleeping for 5 seconds while memory is locked...\n");
    sleep(5);

    // Unlock the memory
    if (munlock(data, size) != 0) {
        perror("munlock");
        free(data);
        return 1;
    }

    // Free the allocated memory
    free(data);

    return 0;
}

