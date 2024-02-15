#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("sample.txt", O_RDWR | O_APPEND);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    int flags = fcntl(fd, F_GETFL, 0);
    flags &= ~O_APPEND;  // Remove O_APPEND flag
    fcntl(fd, F_SETFL, flags);

    // Now, writing to the file won't append to the end
    write(fd, "This will overwrite the file.\n", 30);

    close(fd);
    return 0;
}

