   

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

#define BUF_SIZ (255)
 
/**************************************/
                MAIN
**************************************/
int main(void)
{
	int s, n=0, nbytes, i;
	struct sockaddr_can addr;
	struct can_frame frame;
	struct ifreq ifr;
	char buf[255];
	FILE *out = stdout;
 
	char *ifname = "can0";

	printf("Can Recieve Test\n");
 
	if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)	{
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


	while (1) {
		if ((nbytes = read(s, &frame, sizeof(struct can_frame))) < 0) {
   			perror("read");
			return 1;
		} else {
	    		if (frame.can_id & CAN_EFF_FLAG)
				n = snprintf(buf, BUF_SIZ, "<0x%08x> ", frame.can_id & CAN_EFF_MASK);
    			else
				n = snprintf(buf, BUF_SIZ, "<0x%03x> ", frame.can_id & CAN_SFF_MASK);

			n += snprintf(buf + n, BUF_SIZ - n, "[%d] ", frame.can_dlc);
    	
			for (i = 0; i < frame.can_dlc; i++) {
        		n += snprintf(buf + n, BUF_SIZ - n, "%02x ", frame.data[i]);
			}
    	
			if (frame.can_id & CAN_RTR_FLAG)
				n += snprintf(buf + n, BUF_SIZ - n, "remote request");
	
			printf("Can frames recieved\n");

   			fprintf(out, "%s\n", buf);

		}	
	}

 
	return 0;
}

