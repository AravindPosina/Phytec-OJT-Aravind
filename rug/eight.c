#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define GPIO_EN_17 "/sys/class/gpio/export"
#define GPIO_DIR_17 "/sys/class/gpio/PC17/direction"
#define GPIO_VAL_17 "/sys/class/gpio/PC17/value"
#define GPIO_EN_19 "/sys/class/gpio/export"
#define GPIO_DIR_19 "/sys/class/gpio/PC19/direction"
#define GPIO_VAL_19 "/sys/class/gpio/PC19/value"
#define SWITCH_VAL "/sys/class/gpio/PC12/value"

int main()
{
    int gpio_fd_17, gpio_fd_19, switch_fd;
    char switch_val;
    int switch_count = 0;
    int i;

    // Export GPIO pins for LEDs
    system("echo 17 > /sys/class/gpio/export");
    system("echo 19 > /sys/class/gpio/export");

    // Set direction of GPIO pins to out
    system("echo out > /sys/class/gpio/PC17/direction");
    system("echo out > /sys/class/gpio/PC19/direction");

    // Open GPIO pin for switch (PC12)
    switch_fd = open(SWITCH_VAL, O_RDONLY);
    if (switch_fd < 0) {
        printf("Unable to open the file %s\n", SWITCH_VAL);
        exit(1);
    }

    // Main loop to toggle LEDs based on switch state
    while (1) {
        // Read switch state
        lseek(switch_fd, 0, SEEK_SET); // Reset file pointer
        read(switch_fd, &switch_val, 1);
        
        if (switch_val == '0') { // Switch pressed
            // Increment switch count
            switch_count++;

            // Toggle LED1 based on switch count
            for (i = 0; i < switch_count; i++) {
                // Turn on LED1
                gpio_fd_17 = open(GPIO_VAL_17, O_WRONLY);
                if (gpio_fd_17 < 0) {
                    printf("Unable to open the file %s\n", GPIO_VAL_17);
                    exit(1);
                }
                write(gpio_fd_17, "1", 1); // Turn LED1 on
                close(gpio_fd_17);

                usleep(500000); // Wait for 0.5 seconds

                // Turn off LED1
                gpio_fd_17 = open(GPIO_VAL_17, O_WRONLY);
                if (gpio_fd_17 < 0) {
                    printf("Unable to open the file %s\n", GPIO_VAL_17);
                    exit(1);
                }
                write(gpio_fd_17, "0", 1); // Turn LED1 off
                close(gpio_fd_17);

                usleep(500000); // Wait for 0.5 seconds
            }

            // Toggle LED2 based on switch count
            for (i = 0; i < switch_count * 3; i++) {
                // Turn on LED2
                gpio_fd_19 = open(GPIO_VAL_19, O_WRONLY);
                if (gpio_fd_19 < 0) {
                    printf("Unable to open the file %s\n", GPIO_VAL_19);
                    exit(1);
                }
                write(gpio_fd_19, "1", 1); // Turn LED2 on
                close(gpio_fd_19);

                usleep(500000); // Wait for 0.5 seconds

                // Turn off LED2
                gpio_fd_19 = open(GPIO_VAL_19, O_WRONLY);
                if (gpio_fd_19 < 0) {
                    printf("Unable to open the file %s\n", GPIO_VAL_19);
                    exit(1);
                }
                write(gpio_fd_19, "0", 1); // Turn LED2 off
                close(gpio_fd_19);

                usleep(500000); // Wait for 0.5 seconds
            }

            // Print number of times switch pressed
            printf("Switch pressed %d times\n", switch_count);
        }
    }

    // Close file descriptors
    close(switch_fd);

    return 0;
}
