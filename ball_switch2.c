#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define GPIO_PIN "77"  // Replace with the actual GPIO pin for the onboard LED

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void exportGPIO(const char *gpioPin) {
    FILE *exportFile = fopen("/sys/class/gpio/export", "w");
    if (exportFile == NULL) {
        error("Error exporting GPIO pin");
    }

    fprintf(exportFile, "%s", gpioPin);
    fclose(exportFile);
}

void setGPIODirection(const char *gpioPin, const char *direction) {
    char directionPath[50];
    snprintf(directionPath, sizeof(directionPath), "/sys/class/gpio/gpio%s/direction", gpioPin);

    FILE *directionFile = fopen(directionPath, "w");
    if (directionFile == NULL) {
        error("Error setting direction for GPIO pin");
    }

    fprintf(directionFile, "%s", direction);
    fclose(directionFile);
}

int main() {
    const char *gpioPin = GPIO_PIN;

    // Export GPIO pin
    exportGPIO(gpioPin);

    // Set the GPIO pin direction to out (for writing)
    setGPIODirection(gpioPin, "out");

    while (1) {
        // Control the onboard LED based on your logic (here, we toggle it)
        FILE *ledFile = fopen("/sys/class/gpio/gpio77/value", "w");
        if (ledFile == NULL) {
            error("Error opening LED pin");
        }

        fprintf(ledFile, "1");  // Assuming you want to turn the LED on
        fclose(ledFile);

        // Adjust the sleep duration based on your sensor's update rate
        sleep(1);  // Sleep for 1 second between readings

        // Turn off the LED in the next iteration
        ledFile = fopen("/sys/class/gpio/gpio77/value", "w");
        if (ledFile == NULL) {
            error("Error opening LED pin");
        }

        fprintf(ledFile, "0");  // Assuming you want to turn the LED off
        fclose(ledFile);

        // Sleep before the next iteration
        sleep(1);
    }

    // Unexport GPIO pin before exiting
    FILE *unexportFile = fopen("/sys/class/gpio/unexport", "w");
    if (unexportFile == NULL) {
        error("Error unexporting GPIO pin");
    }

    fprintf(unexportFile, "%s", gpioPin);
    fclose(unexportFile);

    return 0;
}

