#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define DIGITAL_PIN "/sys/class/gpio/gpio77/value"  // Replace with the actual GPIO pin for the onboard LED

void error(const char *msg) {
    perror(msg);
    exit(1);
}

bool readDigitalValue() {
    FILE *fp = fopen(DIGITAL_PIN, "r");
    if (fp == NULL) {
        error("Error opening digital pin");
    }

    char value;
    fscanf(fp, " %c", &value);  // Leading space to skip any leading whitespace
    fclose(fp);

    // '1' indicates the presence of a signal, '0' indicates no signal
    return (value == '1');
}

int main() {
    // Export GPIO pin 77
    FILE *exportFile = fopen("/sys/class/gpio/export", "w");
    if (exportFile == NULL) {
        error("Error exporting GPIO pin");
    }

    fprintf(exportFile, "77");
    fclose(exportFile);

    // Set the GPIO pin direction to out (for writing)
    FILE *directionFile = fopen("/sys/class/gpio/gpio77/direction", "w");
    if (directionFile == NULL) {
        error("Error setting direction for GPIO pin");
    }

    fprintf(directionFile, "out");
    fclose(directionFile);

    while (1) {
        bool ballSwitchState = readDigitalValue();

        // Control the onboard LED based on the state of the ball switch
        FILE *ledFile = fopen(DIGITAL_PIN, "w");
        if (ledFile == NULL) {
            error("Error opening LED pin");
        }

        fprintf(ledFile, "%d", ballSwitchState ? 1 : 0);
        fclose(ledFile);

        // Adjust the sleep duration based on your sensor's update rate
        sleep(1);  // Sleep for 1 second between readings
    }

    // Unexport GPIO pin 77 before exiting
    FILE *unexportFile = fopen("/sys/class/gpio/unexport", "w");
    if (unexportFile == NULL) {
        error("Error unexporting GPIO pin");
    }

    fprintf(unexportFile, "77");
    fclose(unexportFile);

    return 0;
}

