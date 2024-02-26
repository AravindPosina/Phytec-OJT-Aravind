#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define GPIO_EN "/sys/class/gpio/export"
#define GPIO_DIR "/sys/class/gpio/PC17/direction"
#define GPIO_VAL "/sys/class/gpio/PC17/value"
#define SWITCH_VAL "/sys/class/gpio/PC12/value"

int main()
{
    int gpio_fd, switch_fd;
    char switch_val;
    int switch_count = 0;
    int led_state = 0; // 0 for OFF, 1 for ON

    // Export GPIO pin for LED
    system("echo 17 > /sys/class/gpio/export");

    // Set direction of GPIO pin to out
    system("echo out > /sys/class/gpio/PC17/direction");

    // Open GPIO pin for switch (PC12)
    switch_fd = open(SWITCH_VAL, O_RDONLY);
    if (switch_fd < 0) {
        printf("Unable to open the file %s\n", SWITCH_VAL);
        exit(1);
    }

    // Main loop to toggle LED based on switch state
    while (1) {
        // Read switch state
        lseek(switch_fd, 0, SEEK_SET); // Reset file pointer
        read(switch_fd, &switch_val, 1);
        
        if (switch_val == '0') { // Switch pressed
            // Increment switch count
            switch_count++;

            // Toggle LED state
            led_state = !led_state;

            // Set LED state
            gpio_fd = open(GPIO_VAL, O_WRONLY);
            if (gpio_fd < 0) {
                printf("Unable to open the file %s\n", GPIO_VAL);
                exit(1);
            }
            if (led_state)
                write(gpio_fd, "1", 1); // Turn LED on
            else
                write(gpio_fd, "0", 1); // Turn LED off
            close(gpio_fd);

            // Print LED status
            if (led_state)
                printf("LED OFF\n");
            else
                printf("LED ON\n");

            // Print number of times switch pressed
            printf("Switch pressed %d times\n", switch_count);
            
            // Wait for 1 second
            sleep(1);
        }
    }

    // Close file descriptors
    close(switch_fd);

    return 0;
}
