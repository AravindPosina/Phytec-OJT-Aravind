

/********************************
	HEADER FILES
********************************/
#include <stdio.h>    
#include <stdint.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h>   
#include <errno.h>    
#include <termios.h>  
#include <stdlib.h>
#include <sys/ioctl.h>
#include <getopt.h>

#include "uart.h"

/********************************
             MAIN
********************************/
int main(int argc, char *argv[]) 
{
    struct uart_config_t u1;
    struct uart_descriptor_t u2;
    
    u1.uart_dev = argv[1];	
    u1.uart_bdRate = B115200;
    u2.uart_fd = 0;	
    u2.uart_flag = O_RDWR|O_NOCTTY | O_SYNC;		
    u2.uart_str = argv[2];
	
	 printf("\n *** UART TESTING UTILITY *** \n");

    uart_init(&u1,&u2);
    uart_conf(&u1,&u2);
    uart_write(&u2);	

    system("sleep 2");

    uart_read(&u2);

	printf("\n Reading Buff = %s\n\n", u2.uart_str);

    return 0;
}
