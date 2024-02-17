#ifndef _GPIO_H
#define _GPIO_H 

struct gpio_descriptor_t {
	char *gpio_dev;
        int gpio_fd;
        unsigned int gpio_num;
	char* gpio_num_str;
        unsigned int gpio_flag;
        unsigned char buf[100];
        };

/* Below Functions used in GPIO - Library/Test-Program */
int gpio_export(struct gpio_descriptor_t *);
int gpio_set_dir(struct gpio_descriptor_t *, char*);
int gpio_set_value(struct gpio_descriptor_t *, unsigned int);
int gpio_fd_open(struct gpio_descriptor_t *);
int gpio_fd_close(struct gpio_descriptor_t *);

#endif
