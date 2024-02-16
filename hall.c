#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define SENSOR_PIN_ANALOG "/sys/class/gpio/PD25/value"

// Function to read analog sensor value
uint16_t readSensor() {
    FILE *fp;
    uint16_t sensorValue;

    // Open the file for reading
    fp = fopen(SENSOR_PIN_ANALOG, "r");
    if (fp == NULL) {
        perror("Error opening analog input file");
        exit(EXIT_FAILURE);
    }

    // Read the analog sensor value
    if (fscanf(fp, "%hu", &sensorValue) != 1) {
        perror("Error reading analog sensor value");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(fp);

    return sensorValue;
}

int main()
{
    printf("Reading sensor values...\n");

    while (1)
    {
        uint16_t sensorValue = readSensor();
        printf("Sensor Value: %u\n", sensorValue);


        usleep(1000000); // 1 second delay
    }

    return 0;
}
