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
    int led1_state = 0; // 0 for OFF, 1 for ON
    int led2_state = 0; // 0 for OFF, 1 for ON

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

            // Toggle LED states
            if (switch_count % 2 == 1) {
                // Odd switch press: LED1 ON, LED2 OFF
                led1_state = 1;
                led2_state = 0;
            } else {
                // Even switch press: LED1 OFF, LED2 ON
                led1_state = 0;
                led2_state = 1;
            }

            // Set LED states
            gpio_fd_17 = open(GPIO_VAL_17, O_WRONLY);
            if (gpio_fd_17 < 0) {
                printf("Unable to open the file %s\n", GPIO_VAL_17);
                exit(1);
            }
            if (led1_state)
                write(gpio_fd_17, "1", 1); // Turn LED1 on
            else
                write(gpio_fd_17, "0", 1); // Turn LED1 off
            close(gpio_fd_17);

            gpio_fd_19 = open(GPIO_VAL_19, O_WRONLY);
            if (gpio_fd_19 < 0) {
                printf("Unable to open the file %s\n", GPIO_VAL_19);
                exit(1);
            }
            if (led2_state)
                write(gpio_fd_19, "1", 1); // Turn LED2 on
            else
                write(gpio_fd_19, "0", 1); // Turn LED2 off
            close(gpio_fd_19);

            // Print LED states and number of times switch pressed
            printf("Switch pressed %d times\n", switch_count);
            printf("LED1 state: %s\n", led1_state ? "ON" : "OFF");
            printf("LED2 state: %s\n", led2_state ? "ON" : "OFF");
            
            // Wait until switch is released
            while (switch_val == '0') {
                lseek(switch_fd, 0, SEEK_SET); // Reset file pointer
                read(switch_fd, &switch_val, 1);
            }
        }
    }

    // Close file descriptors
    close(switch_fd);

    return 0;
}
