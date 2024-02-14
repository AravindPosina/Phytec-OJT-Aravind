#include <stdio.h>

int main() {
    float matrix[3][3], inverse[3][3];
    float det = 0;

    // Input matrix elements from the user
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Calculate the determinant
    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    if (det == 0) {
        printf("The matrix is singular, and its inverse does not exist.\n");
        return 1;
    }

    // Calculate the inverse matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float cofactor = matrix[(i + 1) % 3][(j + 1) % 3] * matrix[(i + 2) % 3][(j + 2) % 3] - matrix[(i + 1) % 3][(j + 2) % 3] * matrix[(i + 2) % 3][(j + 1) % 3];
            inverse[j][i] = cofactor / det;
        }
    }

    // Display the inverse matrix
    printf("Inverse of the matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", inverse[i][j]);
        }
        printf("\n");
    }

    return 0;
}

