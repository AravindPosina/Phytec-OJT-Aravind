#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fileDescriptor = open("data.txt", O_RDONLY);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        exit(1);
    }
while(1)
{
    char buffer[100];
    ssize_t bytesRead;

    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }
}
    close(fileDescriptor);
    return 0;
}

