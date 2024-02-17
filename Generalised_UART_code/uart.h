#ifndef _UART_H
#define _UART_H

struct uart_config_t {                                                                        
        char *uart_dev;                                                                        
        unsigned int uart_bdRate;                                                                               
        };                                                                                                     
                                                                                                           
struct uart_descriptor_t {                                                                                  
	unsigned int uart_fd;                                                                                        
	char *uart_str;
	int uart_flag;
};

/* Below Functions are used in UART Library/Test-Program */
int uart_init(struct uart_config_t*, struct uart_descriptor_t*);
int uart_conf(struct uart_config_t*, struct uart_descriptor_t*);
int uart_write(struct uart_descriptor_t*);
int uart_read(struct uart_descriptor_t*);

#endif
