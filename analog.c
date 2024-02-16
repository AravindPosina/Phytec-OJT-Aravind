#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mraa.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

float analogToTemperature(int analogValue) {
    // Assuming Vo is directly proportional to analogValue
    float Vo = (float)analogValue;

    float R1 = 10000.0; // Value of R1 on board
    float logR2, R2, T, K;
    float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;

    // Corrected calculation for R2
    R2 = R1 * (1023.0 / Vo - 1.0);
    logR2 = log(R2);
    K = 1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2);

    T = K - 273.15; // Convert Kelvin to Celsius

    return T;
}

int main() {
    mraa_init();  // Initialize MRAA

    mraa_aio_context adc;
    adc = mraa_aio_init(73);  // Replace 73 with the actual MRAA mapped analog pin

    if (adc == NULL) {
        error("Error initializing MRAA");
    }

    while (1) {
        int analogValue = mraa_aio_read(adc);
        if (analogValue < 0) {
            error("Error reading analog value");
        }

        float temperature = analogToTemperature(analogValue);
        printf("Analog Value: %d, Temperature: %.2f\n", analogValue, temperature);

        // Adjust the sleep duration based on your sensor's update rate
        sleep(1);  // Sleep for 1 second between readings
    }

    mraa_aio_close(adc);  // Close MRAA analog pin
    mraa_deinit();        // Deinitialize MRAA

    return 0;
}

