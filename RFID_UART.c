/*********************************************************************************************
 * © 2022 PHYTEC EMBEDDED PVT LTD. - All Rights Reserved. Permission to use, modify, copy, and distribute
 * this source code, object code, or executable code (collectively, Software), is granted only
 * under the terms of a valid written license agreement with PHYTEC. Unauthorized copying
 * or other use of the Software is strictly prohibited.  Software is owned by and constitutes
 * the proprietary works, trade secrets, and copyrights of Embitel or its licensors.
 *
 * For further information, contact PHYTEC EMBEDDED Pvt Ltd.
 *********************************************************************************************/
/*********************************************************************************************/
/*      Application: 03_UART.c
 *
 *      Brief: This application is to check loopback  using UART interface via /dev/fs entries
 *
 *      Author: PHYTEC EMBEDDED PVT LTD
 */
/*********************************************************************************************/


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

	///* save current serial port settings */
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
	//char arr[7]="PHYTEC";
	unsigned char buf1[12] ={0};

	fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd < 0) 
	{
		printf("Error opening %s: %s\n", portname, strerror(errno));
		return -1;
	}
        set_interface_attribs(fd, B9600);
        
        //wlen = write(fd,arr,sizeof(arr));
	//sleep(1);

	rdlen = read(fd, buf1,sizeof(buf1));
	for(int i=0;i<rdlen;i++)
	      printf("%c", buf1[i]);
	      
	printf("\n");


return 0;
}


