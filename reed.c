#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define GPIO_EXPORT_PATH "/sys/class/gpio/export"
#define REED_SWITCH_PIN "/sys/class/gpio/gpio25/value"  // Replace XX with the GPIO pin number

void exportGPIO(const char *gpioPin) {
    FILE *exportFile = fopen(GPIO_EXPORT_PATH, "w");
    if (exportFile == NULL) {
        perror("Error exporting GPIO pin");
        exit(EXIT_FAILURE);
    }

    fprintf(exportFile, "%s", gpioPin);
    fclose(exportFile);
}

void unexportGPIO(const char *gpioPin) {
    FILE *unexportFile = fopen("/sys/class/gpio/unexport", "w");
    if (unexportFile == NULL) {
        perror("Error unexporting GPIO pin");
        exit(EXIT_FAILURE);
    }

    fprintf(unexportFile, "%s", gpioPin);
    fclose(unexportFile);
}

bool readReedSwitch(const char *gpioPin) {
    FILE *fp = fopen(gpioPin, "r");
    if (fp == NULL) {
        perror("Error opening Reed switch pin");
        exit(EXIT_FAILURE);
    }

    char value;
    fscanf(fp, " %c", &value);  // Leading space to skip any leading whitespace
    fclose(fp);

    // '1' indicates the presence of a magnetic field, '0' indicates no magnetic field
    return (value == '1');
}

int main() {
    const char *gpioPin = "25";  // Replace XX with the actual GPIO pin number

    exportGPIO(gpioPin);

    char reedSwitchPin[50];
    snprintf(reedSwitchPin, sizeof(reedSwitchPin), "/sys/class/gpio/gpio%s/value", gpioPin);

    while (1) {
        bool magneticFieldPresent = readReedSwitch(reedSwitchPin);
        printf("Magnetic Field Present: %s\n", magneticFieldPresent ? "Yes" : "No");

        // Adjust the sleep duration based on your sensor's update rate
        sleep(1);  // Sleep for 1 second between readings
    }

    unexportGPIO(gpioPin);

    return 0;
}

