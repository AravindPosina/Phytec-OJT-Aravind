#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define GPIO_EN "/sys/class/gpio/export"
#define GPIO_DIR_17 "/sys/class/gpio/PC17/direction"
#define GPIO_DIR_19 "/sys/class/gpio/PC19/direction"
#define GPIO_VAL_17 "/sys/class/gpio/PC17/value"
#define GPIO_VAL_19 "/sys/class/gpio/PC19/value"
#define SWITCH_VAL "/sys/class/gpio/PC12/value"

int main()
{
    int gpio_fd_17, gpio_fd_19, switch_fd;
    char switch_val;
    int switch_count = 0;

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

            // Toggle LEDs based on switch count
            switch (switch_count) {
                case 1:
                    // Turn on 1st LED (PC17)
                    gpio_fd_17 = open(GPIO_VAL_17, O_WRONLY);
                    if (gpio_fd_17 < 0) {
                        printf("Unable to open the file %s\n", GPIO_VAL_17);
                        exit(1);
                    }
                    write(gpio_fd_17, "1", 1); // Turn LED on
                    close(gpio_fd_17);

                    usleep(500000); // Wait for 0.5 seconds

                    // Turn off 1st LED
                    gpio_fd_17 = open(GPIO_VAL_17, O_WRONLY);
                    if (gpio_fd_17 < 0) {
                        printf("Unable to open the file %s\n", GPIO_VAL_17);
                        exit(1);
                    }
                    write(gpio_fd_17, "0", 1); // Turn LED off
                    close(gpio_fd_17);
                    break;

                case 2:
                    // Turn on 2nd LED (PC19)
                    gpio_fd_19 = open(GPIO_VAL_19, O_WRONLY);
                    if (gpio_fd_19 < 0) {
                        printf("Unable to open the file %s\n", GPIO_VAL_19);
                        exit(1);
                    }
                    write(gpio_fd_19, "1", 1); // Turn LED on
                    close(gpio_fd_19);

                    usleep(500000); // Wait for 0.5 seconds

                    // Turn off 2nd LED
                    gpio_fd_19 = open(GPIO_VAL_19, O_WRONLY);
                    if (gpio_fd_19 < 0) {
                        printf("Unable to open the file %s\n", GPIO_VAL_19);
                        exit(1);
                    }
                    write(gpio_fd_19, "0", 1); // Turn LED off
                    close(gpio_fd_19);
                    break;

                default:
                    // Reset switch count
                    switch_count = 0;
                    break;
            }
        }
    }

    // Close file descriptors
    close(switch_fd);

    return 0;
}
