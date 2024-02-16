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
    tty.c_cflag |= (CLOCAL | CREAD); /* Ignore modem controls */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;            /* 8-bit characters */
    tty.c_cflag &= ~PARENB;        /* No parity bit */
    tty.c_cflag &= ~CSTOPB;        /* Only need 1 stop bit */
    tty.c_cflag &= ~CRTSCTS;       /* No hardware flow control */

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

int main() 
{
    char *portname = "/dev/ttyS3";
    int fd;
    int rdlen;
    unsigned char buf[256]; // Adjust buffer size as needed

    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) 
    {
        printf("Error opening %s: %s\n", portname, strerror(errno));
        return -1;
    }

    if (set_interface_attribs(fd, B9600) != 0) 
    {
        close(fd);
        return -1;
    }

    while (1) 
    {
        rdlen = read(fd, buf, sizeof(buf) - 1); // Read data into the buffer
        if (rdlen > 0) 
        {
            buf[rdlen] = '\0'; // Null-terminate the received data
           // printf("Received data: %s\n", buf);

            // Parse temperature and humidity data
            char *temp_str = strstr(buf, "Temperature:");
            char *humidity_str = strstr(buf, "Humidity:");

            if (temp_str && humidity_str) 
            {
                int temperature, humidity;
                if (sscanf(temp_str, "Temperature: %d", &temperature) == 1 &&
                    sscanf(humidity_str, "Humidity: %d", &humidity) == 1) 
               {
                 printf("Temperature: %d°C, Humidity: %d%%\n", temperature, humidity);
               }
            }
        } else {
            printf("No data received.\n");
        }
    }

    close(fd);
    return 0;
}
