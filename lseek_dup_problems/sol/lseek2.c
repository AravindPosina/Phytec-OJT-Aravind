#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Record {
    // Define your record structure here
};

int main() {
    int fd = open("datafile.bin", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Prompt the user for a record number
    printf("Enter record number: ");
    int recordNumber;
    scanf("%d", &recordNumber);

    off_t pos = lseek(fd, recordNumber * sizeof(struct Record), SEEK_SET);
    if (pos == -1) {
        perror("lseek");
        close(fd);
        exit(1);
    }

    struct Record record;
    ssize_t bytesRead = read(fd, &record, sizeof(struct Record));
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    // Display the record contents here

    close(fd);
    return 0;
}

