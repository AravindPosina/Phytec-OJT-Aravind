#include <stdio.h>

int main() {
    int rows, cols;

   
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

   
    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    
    printf("Matrix entered by the user:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

