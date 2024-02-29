#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>void error(const char *msg) {
perror(msg);
exit(1);
}
int main() {
const char *portname = "/dev/ttyS3"; // Replace with the actual UART device file
int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
if (fd < 0) {
error("Error opening UART");
}
struct termios tty;
if (tcgetattr(fd, &tty) < 0) {
error("Error from tcgetattr");
}
cfsetospeed(&tty, B115200); // Set the baud rate
cfsetispeed(&tty, B115200);
tty.c_cflag |= (CLOCAL | CREAD); // Ignore modem control lines, enable receiver
tty.c_cflag &= ~CSIZE; // Clear data size bits
tty.c_cflag |= CS8; // 8-bit data
tty.c_cflag &= ~PARENB; // No parity bit
tty.c_cflag &= ~CSTOPB; // 1 stop bit
tty.c_cflag &= ~CRTSCTS; // No hardware flow control
tty.c_lflag = 0; // Non-canonical mode
tty.c_cc[VMIN] = 1; // Minimum number of characters to readtty.c_cc[VTIME] = 1; // Time to wait for data (in tenths of a second)
if (tcsetattr(fd, TCSANOW, &tty) != 0) {
error("Error from tcsetattr");
}
while(1)
{
char buf[50];
memset(buf, 0, sizeof(buf));
int n = read(fd, buf, sizeof(buf));
if (n < 0) {
error("Error reading");
}
printf("Received: %s\n", buf);
}
close(fd);
return 0;
