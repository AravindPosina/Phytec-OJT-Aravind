#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main() {
    int fileDescriptor = open("data.txt", O_WRONLY | O_CREAT | O_APPEND , 0644);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        exit(1);
    }
while(1)
{
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    write(fileDescriptor, input, strlen(input));

}
    close(fileDescriptor);
    return 0;
}

