#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
int set_interface_attribs(int fd, int speed)
{
        struct termios tty;

        if (tcgetattr(fd, &tty) < 0) 
        {
                printf("Error from tcgetattr: %s\n", strerror(errno));
                return -1;
        }

        cfsetispeed(&tty, (speed_t)speed);
        tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
        tty.c_cflag &= ~CSIZE;
        tty.c_cflag |= CS8;         /* 8-bit characters */
        tty.c_cflag &= ~PARENB;     /* no parity bit */
        tty.c_cflag &= ~CSTOPB;     /* only need 1 stop bit */
        tty.c_cflag &= ~CRTSCTS;    /* no hardware flowcontrol */


        tty.c_iflag = IGNPAR;
        tty.c_lflag = 0;

        
        tty.c_cc[VMIN] = 1;
        tty.c_cc[VTIME] = 1;

        if (tcsetattr(fd, TCSANOW, &tty) != 0) 
        {
                printf("Error from tcsetattr: %s\n", strerror(errno));
                return -1;
        }
        return 0;
}

int main()
{
    char *portname = "/dev/ttyS3";
    int fd;
    int wlen;
    int rdlen;
    int ret;

    char res[5];
    char arr1[] = "CMD+RESET\r\n"; 
    char arr2[] = "CMD+WIFIMODE=1\r\n";
    char arr[] = "CMD+CONTOAP=\"iQOO Neo6\",\"123456788\"\r\n";  
    char arr3[] = "CMD+MQTTNETCFG=dev.rightech.io,1883\r\n";
    char arr4[] = "CMD+MQTTCONCFG=3,mqtt-eminriyaz-oseq75,,,,,,,,,\r\n";
    char arr5[] = "CMD+MQTTSTART=1\r\n";
    char arr6[] = "CMD+MQTTSUB=base/relay/led1\r\n";

    unsigned char buf[100];  

    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) 
    {
        printf("Error opening %s: %s\n", portname, strerror(errno));
        return -1;
    }
    set_interface_attribs(fd, B38400);

    printf("%s", arr1);
    wlen = write(fd, arr1, sizeof(arr1) - 1);  
    sleep(3);
    

    // Send CMD+WIFIMODE=1
    printf("%s", arr2);
    wlen = write(fd, arr2, sizeof(arr2) - 1);
    sleep(3);
    

    // Send CMD+CONTOAP
    printf("%s", arr);
    wlen = write(fd, arr, sizeof(arr) - 1);
    sleep(3);
    
    
    printf("%s", arr3);
    wlen = write(fd, arr3, sizeof(arr3) - 1);
    sleep(3);
    
    
    printf("%s", arr4);
    wlen = write(fd, arr4, sizeof(arr4) - 1);
    sleep(3);
    

    printf("%s", arr5);
    wlen = write(fd, arr5, sizeof(arr5) - 1);
    sleep(3);
      
    printf("%s", arr6);
    wlen = write(fd, arr6, sizeof(arr6) - 1);
    sleep(3);
    
char buffer[100]; // Create a buffer to hold the formatted message
   
while(1){
ssize_t rdlen = read(fd, buffer, sizeof(buffer) - 1);
        if (rdlen > 0) {
            buffer[rdlen] = '\0';  // Null-terminate the received data

            // Parse temperature and humidity data
            int temperature, humidity;
            if (sscanf(buffer, "%d,%d", &temperature, &humidity) == 2) {
                printf("Temperature: %d°C, Humidity: %d%%\n", temperature, humidity);

                // Send the data to the cloud using your CMD+MQTTPUB commands
                char pub_temperature[100], pub_humidity[100];
                snprintf(pub_temperature, sizeof(pub_temperature), "CMD+MQTTPUB=base/state/temperature,%d\r\n", temperature);
                snprintf(pub_humidity, sizeof(pub_humidity), "CMD+MQTTPUB=base/state/humidity,%d\r\n", humidity);

                write(fd, pub_temperature, strlen(pub_temperature));
                usleep(1000000);  // Wait for 1 second
                write(fd, pub_humidity, strlen(pub_humidity));
                usleep(1000000);  // Wait for 1 second
            }
        } else {
            printf("No data received.\n");
        }
    }

    close(fd);
    return 0;
}
