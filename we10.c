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
        printf("Error from tcgetattr: %s\n", strerror(errno));
        return -1;
    }

    cfsetispeed(&tty, (speed_t)speed);
    cfsetospeed(&tty, (speed_t)speed);

    tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;         /* 8-bit characters */
    tty.c_cflag &= ~PARENB;     /* no parity bit */
    tty.c_cflag &= ~CSTOPB;     /* only need 1 stop bit */
    tty.c_cflag &= ~CRTSCTS;    /* no hardware flow control */

    tty.c_iflag = IGNPAR;
    tty.c_lflag = 0;

    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1;

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        printf("Error from tcsetattr: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

void send_second_set_of_commands(int fd) {
    char arr1_new[] = "CMD+RESET\r\n";
    char arr2[] = "CMD+WIFIMODE=1\r\n";
    // Add other commands for the second set as needed

    printf("%s", arr1_new);
    write(fd, arr1_new, sizeof(arr1_new) - 1);
    tcdrain(fd);  // Flush output
    sleep(2);

    printf("%s", arr2);
    write(fd, arr2, sizeof(arr2) - 1);
    tcdrain(fd);  // Flush output
    sleep(2);

    // Add other commands for the second set as needed
}

int main() {
    char *portname = "/dev/ttyS3";
    int fd;
    int rdlen;
    unsigned char buf[192];

    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        printf("Error opening %s: %s\n", portname, strerror(errno));
        return -1;
    }

    // Set serial interface attributes for the second set of commands
    set_interface_attribs(fd, B115200);

    send_second_set_of_commands(fd);

    while (1) {
        // Your existing code for reading and processing data
        rdlen = read(fd, buf, sizeof(buf) - 1);
        if (rdlen > 0) {
            buf[rdlen] = '\0';
            printf("Received data: %s\n", buf);
        }
    }

    close(fd);
    return 0;
}

