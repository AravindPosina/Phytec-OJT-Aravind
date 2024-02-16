/********************************
        HEADER FILES
********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include "gpio.h"

/* GPIO - EXPORT */
int gpio_export(struct gpio_descriptor_t  *gpio_desc)
{

	 gpio_desc->gpio_fd = open(gpio_desc->gpio_dev, gpio_desc->gpio_flag);

	sprintf(gpio_desc->buf, "%s", gpio_desc->gpio_num_str);

	 write(gpio_desc->gpio_fd, gpio_desc->buf, strlen(gpio_desc->buf));
}

/* GPIO - SET DIRECTION */
int gpio_set_dir(struct gpio_descriptor_t *gpio_desc, char* dir)
{
	int setdir_fd;
	
	if(63 < gpio_desc->gpio_num < 96) 
		sprintf(gpio_desc->buf, "/sys/class/gpio/PC%d/direction", ((gpio_desc->gpio_num)-(2*32)));
	//printf("gpio_desc->buf: %s\n",gpio_desc->buf);

	  setdir_fd  = open(gpio_desc->buf, gpio_desc->gpio_flag);


        //  write(setdir_fd, dir, 4);
	if(dir)
                write(setdir_fd, "out", 4);
        else
                write(setdir_fd, "in", 3);
	
	close(gpio_desc->gpio_fd);

}

/* GPIO - SET VALUE */
int gpio_set_value(struct gpio_descriptor_t *gpio_desc, unsigned int val)
{

	int setval_fd;

        if(63 < gpio_desc->gpio_num < 96)
                sprintf(gpio_desc->buf, "/sys/class/gpio/PC%d/value", ((gpio_desc->gpio_num)-(2*32)));


	  setval_fd = open(gpio_desc->buf, gpio_desc->gpio_flag);
		
	if (val)
	        write(setval_fd, "1", 2);
        else
                write(setval_fd, "0", 2);

	return 0;

	close(gpio_desc->gpio_fd);
}

/* GPIO - CLOSE(fd) */
int gpio_fd_close(struct gpio_descriptor_t *gpio_desc)
{
        close(gpio_desc->gpio_fd);
        gpio_desc->gpio_fd = -1;

        return 0;
}


