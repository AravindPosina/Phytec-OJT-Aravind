#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    
    char **pattern = (char **)calloc(rows, sizeof(char *));
    if (pattern == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Return with error
    }

    
    for (i = 0; i < rows; i++) {
        pattern[i] = (char *)calloc(i + 1, sizeof(char));
        if (pattern[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1; 
        }
    }

  
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            pattern[i][j] = '*';
        }
    }

   
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }
 

    for (i = 0; i < rows; i++) {
        free(pattern[i]);
    }
    free(pattern);

    return 0;
}

