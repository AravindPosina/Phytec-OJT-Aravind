#include <stdio.h>

#define SIZE 3


double determinant3x3(double matrix[SIZE][SIZE]) {
    double det = 0;

    for (int i = 0; i < SIZE; i++) {
        det += matrix[0][i] * (matrix[1][(i + 1) % SIZE] * matrix[2][(i + 2) % SIZE] -
                               matrix[1][(i + 2) % SIZE] * matrix[2][(i + 1) % SIZE]);
    }

    return det;
}

int main() {
    double matrix[SIZE][SIZE];

    
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    
    double det = determinant3x3(matrix);
    printf("Determinant of the matrix: %.2f\n", det);

    return 0;
}

