#include<stdio.h>
#include <stdlib.h>

int* generateArray(int n)
{
    int* array = (int*)malloc(n * sizeof(int));
    int i;
    
    for (i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }
    return array;
}

void main()
{
    int i = 0, n = 10;
    int* arr = generateArray(n);
    
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}
