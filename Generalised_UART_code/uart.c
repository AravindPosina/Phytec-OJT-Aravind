 
#include <stdio.h>  
#include <stdlib.h> 	
#include <stdint.h> 
#include <string.h> 
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <getopt.h>

#include "uart.h"

/* UART - INIT */
int uart_init(struct uart_config_t* u1, struct uart_descriptor_t* u2)
{
    u2->uart_fd = open(u1->uart_dev,u2->uart_flag);
   
    if (u2->uart_fd == -1) 
    {
        perror("init_serialport: Unable to open port ");
        return -1;
    }
}

/* UART - CONFIGURATION */
int uart_conf(struct uart_config_t* u1, struct uart_descriptor_t* u2)
{

    struct termios toptions;
   	 if (tcgetattr(u2->uart_fd, &toptions) < 0)
	 {
        	perror("init_serialport: Couldn't get term attributes");
	        return -1;
	 }

    speed_t brate = u1->uart_bdRate; // let you override switch below if needed

      switch(u1->uart_bdRate)
      {
   	    case 4800:   brate=B4800;   break;
	    case 9600:   brate=B9600;   break;
	    case 19200:  brate=B19200;  break;
	    case 38400:  brate=B38400;  break;
	    case 57600:  brate=B57600;  break;
	    case 115200: brate=B115200; break;
      } 

    cfsetispeed(&toptions, brate);
    cfsetospeed(&toptions, brate);
    /*toptions.c_cflag &= ~PARENB;
    toptions.c_cflag &= ~CSTOPB;
    toptions.c_cflag &= ~CSIZE;
    toptions.c_cflag |= CS8;
    toptions.c_cflag &= ~CRTSCTS;
    toptions.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines
    toptions.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl
    toptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
    toptions.c_oflag &= ~OPOST; // make raw
    toptions.c_cc[VMIN]  = 0;
    toptions.c_cc[VTIME] = 20;*/
    toptions.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
    toptions.c_cflag &= ~CSIZE;
    toptions.c_cflag |= CS8;         /* 8-bit characters */
    toptions.c_cflag &= ~PARENB;     /* no parity bit */
    toptions.c_cflag &= ~CSTOPB;     /* only need 1 stop bit */
    toptions.c_cflag &= ~CRTSCTS;    /* no hardware flowcontrol */


        toptions.c_iflag = IGNPAR;
        toptions.c_lflag = 0;


	toptions.c_cc[VMIN] = 1;
	toptions.c_cc[VTIME] = 1;

    if( tcsetattr(u2->uart_fd, TCSANOW, &toptions) != 0)
    {
   	 perror("init_serialport: Couldn't set term attributes");
	 return -1;
    }

	 return u2->uart_fd;

}

/* UART - WRITE */
int uart_write(struct uart_descriptor_t* u2)
{
	int len, wr_len;

    	len = strlen(u2->uart_str);
	    wr_len = write(u2->uart_fd, u2->uart_str, len);
   	 if( wr_len != len )
	 {
        	return -1;
	 }	
		
		return wr_len;
}

/* UART - READ */
int uart_read(struct uart_descriptor_t* u2)
{
	int rd =  read(u2->uart_fd, u2->uart_str, sizeof(u2->uart_str));   
 
	if(rd < 0)
	{
		return -1;
	}
}
