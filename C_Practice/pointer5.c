#include<stdio.h>

int greatest(int *, int);

int main()
{
    int arr[6] = {4,5,22,77,23,1};
    int max_value = greatest(arr, 6);
    printf("Greatest value in array = %d", max_value);
    return 0;
}

int greatest(int *arr, int n)
{ 
    int max_element = arr[0], i;
    for(i = 0; i < n; i++)
    {
        if (max_element < arr[i])
       	{
            max_element = arr[i];
        }
    }
    return max_element;
}
