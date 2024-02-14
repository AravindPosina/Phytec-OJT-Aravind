#include<stdio.h>

int main()
{
    int rows = 5;

    for (int i = rows; i >= 1; i--) // Loop for each row
    {
        for (int j = 1; j <= rows - i; j++) // Loop for printing spaces
        {
            printf(" ");
        }

        for (int k = 1; k <= 2 * i - 1; k++) // Loop for printing stars
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

