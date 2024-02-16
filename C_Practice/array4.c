#include<stdio.h>

void printArray(int array[3][3]);

void main()
{
    int arr[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    printArray(arr);
}

void printArray(int array[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
       	{
            printf("%d ", array[i][j]);
        }        
        printf("\n");
    }
}

