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
        printf("Error from tcsetattr: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

void send_command(int fd, const char* command) {
    printf("Sending command: %s", command);
    write(fd, command, strlen(command));

    // Wait for a short time (adjust as needed)
    sleep(2);
}

void read_response(int fd) {
    unsigned char buf[100];
    int rdlen = read(fd, buf, sizeof(buf) - 1);

    if (rdlen > 0) {
        buf[rdlen] = '\0';
        printf("Received data: %s\n", buf);
    }
}

int main() {
    char *portname = "/dev/ttyS3";
    int fd;
    int wlen;

    char arr1[] = "CMD+RESET=0\r\n";
    char arr7[] = "CMD+SCAN=1\r\n";
    char arr8[] = "CMD+CON=1,d83251c5372c\r\n";
    char arr9[] = "CMD+DATA=<conn_handle>,hi\r\n";

    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        printf("Error opening %s: %s\n", portname, strerror(errno));
        return -1;
    }

    set_interface_attribs(fd, B115200);

    // Send and read responses for each command
    send_command(fd, arr1);
    read_response(fd);

    send_command(fd, arr7);
    read_response(fd);

    send_command(fd, arr8);
    read_response(fd);

    send_command(fd, arr9);
    read_response(fd);

    close(fd);
    return 0;
}

