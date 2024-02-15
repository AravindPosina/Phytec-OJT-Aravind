#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *addr;
    const char *file_name = "mapped_file.txt";

    // Open a file for memory mapping
    fd = open(file_name, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Map the file into memory
    addr = (char *)mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Prompt user for input and write it to the memory-mapped file
    printf("Enter text to write to the memory-mapped file: ");
    fgets(addr, 100, stdin);

    // Unmap the memory and close the file
    munmap(addr, 100);
    close(fd);

    return 0;
}

