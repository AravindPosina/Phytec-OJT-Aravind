#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < colSecond; ++j) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < colSecond; ++j) {
            for (int k = 0; k < colFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowFirst, colFirst, rowSecond, colSecond;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &colFirst);

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &colSecond);

    if (colFirst != rowSecond) {
        printf("Error! Number of columns in the first matrix should be equal to the number of rows in the second matrix.\n");
        return 0;
    }

    int firstMatrix[MAX_SIZE][MAX_SIZE], secondMatrix[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rowFirst; ++i)
        for (int j = 0; j < colFirst; ++j)
            scanf("%d", &firstMatrix[i][j]);

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rowSecond; ++i)
        for (int j = 0; j < colSecond; ++j)
            scanf("%d", &secondMatrix[i][j]);

    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, colFirst, rowSecond, colSecond);

    printf("Product of matrices:\n");
    displayMatrix(result, rowFirst, colSecond);

    return 0;
}

