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
/*      Application: 
                        cansender.c
 *
 *      Brief: This application is to communicate Two Boards using CAN interface via sockets
 *
 *      Author: PHYTEC EMBEDDED PVT LTD
 */
/*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
 
#include <linux/can.h>
#include <linux/can/raw.h>
 
/**********************************
	      MAIN	 
**********************************/
int main(void)
{
	int s, nbytes;
	struct sockaddr_can addr;
	struct can_frame frame;
	struct ifreq ifr;
 
	char *ifname = "can0";

	printf("Can Send Test\n");
 
	if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Error while opening socket");
		return -1;
	}
 
	strcpy(ifr.ifr_name, ifname);
	ioctl(s, SIOCGIFINDEX, &ifr);
 
	addr.can_family  = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex; 
 
	printf("%s at index %d\n", ifname, ifr.ifr_ifindex);
 
	if(bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Error in socket bind");
		return -2;
	}
 
	frame.can_id  = 0x123;
	frame.can_dlc = 2;
	frame.data[0] = 0x11;
	frame.data[1] = 0x22;
 
	nbytes = write(s, &frame, sizeof(struct can_frame));
 
	printf("Wrote %d bytes\n", nbytes);
 
	return 0;
}


