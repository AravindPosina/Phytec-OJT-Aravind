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
    tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;                 /* 8-bit characters */
    tty.c_cflag &= ~PARENB;             /* no parity bit */
    tty.c_cflag &= ~CSTOPB;             /* only need 1 stop bit */
    tty.c_cflag &= ~CRTSCTS;            /* no hardware flow control */

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

void send_command(int fd, const char *command) {
    int wlen = write(fd, command, strlen(command));
    if (wlen == -1) {
        printf("Error writing to UART: %s\n", strerror(errno));
    }
    sleep(3);
}

int main() {
    char *portname = "/dev/ttyS3";
    int fd;
    int rdlen;

    char arr1[] = "CMD+RESET=0\r\n";
    char arr2[] = "CMD+HWFC=1\r\n";
    char arr3[] = "CMD+RESET=0\r\n";
    char arr4[] = "CMD+ADV=1\r\n";
    char arr5[] = "CMD+TXPWR=-4\r\n";
    char arr6[] = "CMD+SCAN=1\r\n";
    char arr7[] = "CMD+CON=1,df4e58635a8b\r\n";
    char arr8[] = "CMD+DATA=<conn_handle>,hiii\r\n";

    unsigned char buf[256];

    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        printf("Error opening %s: %s\n", portname, strerror(errno));
        return -1;
    }

    set_interface_attribs(fd, B115200);

    printf("%s", arr1);
    send_command(fd, arr1);

    // Bluetooth Configuration
    printf("%s", arr2);
    send_command(fd, arr2);

    printf("%s", arr3);
    send_command(fd, arr3);

    printf("%s", arr4);
    send_command(fd, arr4);
printf("%s", arr5);                                             
    send_command(fd, arr5);
printf("%s", arr6);                                             
    send_command(fd, arr6);
printf("%s", arr7);                                             
    send_command(fd, arr7);
printf("%s", arr8);                                             
    send_command(fd, arr8);    

    // Placeholder for more Bluetooth commands as needed
    // ...

    char buffer[256]; // Create a buffer to hold the formatted message

    while (1) {
        rdlen = read(fd, buf, sizeof(buf) - 1);
        if (rdlen > 0) {
            buf[rdlen] = '\0'; // Null-terminate the received data
            printf("%s\n", buf);

            // Placeholder for processing and sending Bluetooth responses
            // ...

            int ret = snprintf(buffer, sizeof(buffer), "CMD+RESPONSE_PROCESSING,%s\r\n", buf);

            if (ret < 0) {
                // Handle snprintf error
            } else {
                ssize_t wlen = write(fd, buffer, ret);
                sleep(3);
                if (wlen == -1) {
                    // Handle write error
                }
            }
        }
    }

    close(fd);
    return 0;
}
