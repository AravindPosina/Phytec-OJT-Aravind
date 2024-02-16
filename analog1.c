
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#define ANALOG_PIN "/sys/bus/iio/devices/iio:device0/in_voltage0_raw" 

void error(const char *msg) {
    perror(msg);
    exit(1);
}

float analogToTemperature(int analogValue) {
    
    float Vo = (float)analogValue;

    float R1 = 10000.0; // Value of R1 on board
    float logR2, R2, T, K;
    float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;

    // Corrected calculation for R2
    R2 = R1 * (1023.0 / Vo - 1.0);
    logR2 = log(R2);
    K = 1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2);

    T = K - 232.15; // Convert Kelvin to Celsius

    return T;
}

int readAnalogValue() {
    FILE *fp = fopen(ANALOG_PIN, "r");
    if (fp == NULL) {
        error("Error opening analog pin");
    }

    int analogValue;
    fscanf(fp, "%d", &analogValue);
    fclose(fp);

    return analogValue;
}

int main() {
    while (1) {
        int analogValue = readAnalogValue();
        float temperature = analogToTemperature(analogValue);
        printf("Analog Value: %d, Temperature: %.2f\n", analogValue, temperature);

        // Adjust the sleep duration based on your sensor's update rate
        sleep(1);  // Sleep for 1 second between readings
    }

    return 0;
}

