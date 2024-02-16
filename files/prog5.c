#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main() {
    // Open the log file "log.txt" in append mode or create it if it doesn't exist
    int logfd = open("log.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

    if (logfd == -1) {
        perror("Error opening the log file");
        return 1; // Exit with an error code
    }

    // Prompt the user to enter a log message
    char logMessage[1024];
    printf("Enter a log message: ");
    fgets(logMessage, sizeof(logMessage), stdin);

    // Get the current timestamp
    time_t currentTime;
    struct tm *timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);

    // Format the timestamp as a string
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeInfo);

    // Write the log message along with the timestamp to the log file
    dprintf(logfd, "[%s] %s", timestamp, logMessage);

    // Close the log file
    close(logfd);

    return 0; // Exit with success
}

