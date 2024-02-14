#include <stdio.h>

int main() {
    double real1, imag1, real2, imag2, result_real, result_imag;


    printf("Enter real and imaginary parts of the first complex number:\n");
    scanf("%lf %lf", &real1, &imag1);


    printf("Enter real and imaginary parts of the second complex number:\n");
    scanf("%lf %lf", &real2, &imag2);


    if (real2 == 0 && imag2 == 0) {
        printf("Error: Division by zero is undefined.\n");
    } else {

        double denominator = real2 * real2 + imag2 * imag2;

        result_real = (real1 * real2 + imag1 * imag2) / denominator;
        result_imag = (imag1 * real2 - real1 * imag2) / denominator;

        printf("Result of division: %.2f + %.2fi\n", result_real, result_imag);
    }

    return 0;
}

