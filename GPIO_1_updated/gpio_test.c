#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include "gpio.h"

int main(int argc, char **argv, char **envp)
{
	int val; char* dir;
	struct gpio_descriptor_t gpio_desc;

	gpio_desc.gpio_dev =  "/sys/class/gpio/export";
	gpio_desc.gpio_flag = O_WRONLY;
	gpio_desc.gpio_num = atoi(argv[1]);
	gpio_desc.gpio_num_str = argv[1];

	dir = argv[2];
	val = atoi(argv[3]);
	//printf("dir : %s val : %d gpio_desc.gpio_num : %d\n ",dir,val,gpio_desc.gpio_num);
	
	printf("\n   *** GPIO TESTING UTILITY ***   \n");

	gpio_export(&gpio_desc);
	gpio_set_dir(&gpio_desc, dir);
 	gpio_set_value(&gpio_desc, val);

	gpio_fd_close(&gpio_desc);
	return 0;
}
