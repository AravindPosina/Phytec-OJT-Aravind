#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main() {
    int fileDescriptor = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        exit(1);
    }

    char message[100];
    printf("Enter log message: ");
    fgets(message, sizeof(message), stdin);

    time_t currentTime;
    time(&currentTime);
    char *timestamp = ctime(&currentTime);

    dprintf(fileDescriptor, "[%s] %s", timestamp, message);

    close(fileDescriptor);
    return 0;
}

