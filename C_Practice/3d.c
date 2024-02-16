#include <stdio.h>

int main() {
    // Define a 3D array to represent a 3x3x3 cube
    int cube[3][3][3] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
        {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}
    };

    // Calculate the sum of all elements in the cube
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                sum += cube[i][j][k];
            }
        }
    }

    // Print the cube and its sum
    printf("3x3x3 Cube:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("cube[%d][%d][%d] = %d\n", i, j, k, cube[i][j][k]);
            }
        }
    }
    
    printf("Sum of all elements in the cube: %d\n", sum);

    return 0;
}

