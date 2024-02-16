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

void send_first_set_of_commands(int fd) {
    char arr1[] = "CMD+RESET=0\r\n";
    char arr4[] = "CMD+ADV=1\r\n";
    char arr5[] = "CMD+TXPWR=-4\r\n";
    char arr6[] = "CMD+SCAN=1\r\n";
//    char arr8[] = "CMD+CON=1,fab321a20744\r\n";

    printf("%s", arr1);
    write(fd, arr1, sizeof(arr1) - 1);
    tcdrain(fd);  // Flush output
    sleep(2);

    printf("%s", arr4);
    write(fd, arr4, sizeof(arr4) - 1);
    tcdrain(fd);  // Flush output
    sleep(2);

    printf("%s", arr5);
    write(fd, arr5, sizeof(arr5) - 1);
    tcdrain(fd);  // Flush output
    sleep(2);

    printf("%s", arr6);
    write(fd, arr6, sizeof(arr6) - 1);
    tcdrain(fd);  // Flush output
    sleep(2);

//    printf("%s", arr8);
  //  write(fd, arr8, sizeof(arr8) - 1);
    //tcdrain(fd);  // Flush output
    //sleep(2);
}

void send_second_set_of_commands(int fd) {
    char arr1_new[] = "CMD+RESET\r\n";
    char arr2[] = "CMD+WIFIMODE=1\r\n";
    char arr3[] = "CMD+CONTOAP=\"Realme 5.0GHz\",\"12345678\"\r\n";     
    char arr4[] = "CMD+MQTTNETCFG=dev.rightech.io:1883\r\n";           
    char arr5[] = "CMD+MQTTCONCFG=3,mqtt-elmanjunath04-8gnaz2,,,,,,,,,\r\n";
    char arr6[] = "CMD+MQTTSTART=1\r\n";
    char arr7[] =  "CMD+MQTTSUB=base/state/temperature\r\n"; 
    char arr8[] = "CMD+CON=1,fab321a20744\r\n";

    // Add other commands for the second set as needed

    printf("%s", arr1_new);
    write(fd, arr1_new, sizeof(arr1_new) - 1);
    tcdrain(fd);  // Flush output
    sleep(2);

    printf("%s", arr2);
    write(fd, arr2, sizeof(arr2) - 1);
    tcdrain(fd);  // Flush output
    sleep(2);
printf("%s", arr3);                                                      
    write(fd, arr3, sizeof(arr3) - 1);                                       
    tcdrain(fd);  // Flush output                                            
    sleep(2); 
printf("%s", arr4);                                                      
    write(fd, arr4, sizeof(arr4) - 1);                                       
    tcdrain(fd);  // Flush output                                            
    sleep(2); 
printf("%s", arr5);                                                      
    write(fd, arr5, sizeof(arr6) - 1);                                       
    tcdrain(fd);  // Flush output                                            
    sleep(2); 
printf("%s", arr6);                                                      
    write(fd, arr6, sizeof(arr6) - 1);                                       
    tcdrain(fd);  // Flush output                                            
    sleep(2);
printf("%s", arr7);                                                       
    write(fd, arr7, sizeof(arr7) - 1);                                     
    tcdrain(fd);  // Flush output                                          
    sleep(2);
 printf("%s", arr8);                  
    write(fd, arr8, sizeof(arr8) - 1);
    tcdrain(fd);  // Flush output                                  
    sleep(2);              

    // Add other commands for the second set as needed
}

int main() {
    char *portname1 = "/dev/ttyS3";  // Port for the first set of commands
    char *portname2 = "/dev/ttyS4";  // Port for the second set of commands

    int fd1, fd2;
    int rdlen;
    unsigned char buf[192];

    // Open the first serial port for the first set of commands
    fd1 = open(portname1, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd1 < 0) {
        printf("Error opening %s: %s\n", portname1, strerror(errno));
        return -1;
    }

    // Open the second serial port for the second set of commands
    fd2 = open(portname2, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd2 < 0) {
        printf("Error opening %s: %s\n", portname2, strerror(errno));
        close(fd1);
        return -1;
    }

    // Set serial interface attributes for the first set of commands
    set_interface_attribs(fd1, B115200);

    send_first_set_of_commands(fd1);

    // Set serial interface attributes for the second set of commands
    set_interface_attribs(fd2, B115200);

    send_second_set_of_commands(fd2);

    while (1) {
        // Your existing code for reading and processing data from both ports
        rdlen = read(fd1, buf, sizeof(buf) - 1);
        if (rdlen > 0) {
            buf[rdlen] = '\0';
            printf("Received data from port 1: %s\n", buf);
        }

        rdlen = read(fd2, buf, sizeof(buf) - 1);
        if (rdlen > 0) {
            buf[rdlen] = '\0';
            printf("Received data from port 2: %s\n", buf);
int ret = snprintf(buf, sizeof(buf), "CMD+MQTTPUB=base/state/temperature,%s\r\n", buf);
    
    if (ret < 0) {
        
    } else {
        
        ssize_t wlen = write(fd2, buf, ret);
        sleep(3);
        if (wlen == -1) {
        }
}    
}
}

    // Close both ports
    close(fd1);
    close(fd2);

    return 0;
}

