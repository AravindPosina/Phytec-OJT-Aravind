/* standard headers */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* mraa header */
#include "mraa/uart.h"

#define UART "/dev/ttyS3"

volatile sig_atomic_t flag = 1;

void
sig_handler(int signum)
{
    if (signum == SIGINT) {
        fprintf(stdout, "Exiting...\n");
        flag = 0;
    }
}

int
main(int argc, char** argv)
{
    mraa_uart_context uart;
    char buffer[] = "Hello Mraa!";

    /* install signal handler */
    signal(SIGINT, sig_handler);

    /* initialize mraa for the platform (not needed most of the times) */
    mraa_init();

    //! [Interesting]
    /* initialize UART */
    uart = mraa_uart_init_raw(UART);
    if (uart == NULL) {
        fprintf(stderr, "Failed to initialize UART\n");
        goto err_exit;
    }

    while (flag) {
        /* send data through UART */
        mraa_uart_write(uart, buffer, sizeof(buffer));

        sleep(1);
        mraa_uart_read(uart, buffer, sizeof(buffer));
    }

    /* stop UART */
    mraa_uart_stop(uart);

    //! [Interesting]
    /* deinitialize mraa for the platform (not needed most of the times) */
    mraa_deinit();

    return EXIT_SUCCESS;

err_exit:
    /* deinitialize mraa for the platform (not needed most of the times) */
    mraa_deinit();

    return EXIT_FAILURE;
}




