#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int nice_value = 0;

    printf("Initial nice value: %d\n", nice(0));

    // Increase niceness (lower priority)
    nice_value = nice(10);
    printf("Increased nice value: %d\n", nice_value);

    // Decrease niceness (higher priority)
    nice_value = nice(-5);
    printf("Decreased nice value: %d\n", nice_value);

    // Run a CPU-bound task
    for (int i = 0; i < 100000000; i++) {
        // Do some computation
    }

    return 0;
}

