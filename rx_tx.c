#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int set_interface_attribs(int fd, int speed) {
    struct termios tty;

    if (tcgetattr(fd, &tty) < 0) {
        perror("Error from tcgetattr");
        return -1;
    }

    cfsetispeed(&tty, (speed_t)speed);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    tty.c_iflag = IGNPAR;
    tty.c_lflag = 0;

    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1;

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        return -1;
    }

    // Flush input and output buffers
    if (tcflush(fd, TCIOFLUSH) != 0) {
        perror("Error flushing buffers");
        return -1;
    }

    return 0;
}

int main() {
    char *portname_tx = "/dev/ttyS3";  // Transmitter (send data)
    char *portname_rx = "/dev/ttyS5";  // Receiver (receive looped back data)
    int fd_tx, fd_rx;
    int wlen, rdlen;
    int ret;

    char user_input[256];
    printf("Enter message to transmit: ");
    fgets(user_input, sizeof(user_input), stdin);

    // Open transmitter port
    fd_tx = open(portname_tx, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd_tx < 0) {
        perror("Error opening transmitter port");
        return -1;
    }

    // Open receiver port
    fd_rx = open(portname_rx, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd_rx < 0) {
        perror("Error opening receiver port");
        close(fd_tx);
        return -1;
    }

    // Set attributes for both ports
    if (set_interface_attribs(fd_tx, B115200) != 0 || set_interface_attribs(fd_rx, B115200) != 0) {
        perror("Error setting interface attributes");
        close(fd_tx);
        close(fd_rx);
        return -1;
    }

    // Loopback mechanism
    wlen = write(fd_tx, user_input, strlen(user_input));
    if (wlen < 0) {
        perror("Error writing to transmitter port");
        close(fd_tx);
        close(fd_rx);
        return -1;
    }

    sleep(1);

    // Read the looped back data
    rdlen = read(fd_rx, user_input, sizeof(user_input));
    if (rdlen < 0) {
        perror("Error reading from receiver port");
        close(fd_tx);
        close(fd_rx);
        return -1;
    }

    printf("Received: %.*s\n", rdlen, user_input);

    close(fd_tx);
    close(fd_rx);

    return 0;
}

