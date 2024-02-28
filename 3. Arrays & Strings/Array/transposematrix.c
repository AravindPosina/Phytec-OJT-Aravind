#include <stdio.h>

int main() {
    int matrix[10][10];
    int rows, cols;

    // Input matrix dimensions
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transpose the matrix in-place
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            // Swap matrix[i][j] and matrix[j][i]
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Display the transposed matrix
    printf("Transposed Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

