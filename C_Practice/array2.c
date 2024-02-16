#include<stdio.h>

void BubbleSort(int array[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (array[j] < array[i])
      {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

  }
}

void main() {
  int arr[6] = {1, 4, 6, 2, 6, 5};
  BubbleSort(arr, 6);
  printf("Sorted array = ");
  int i = 0;
  for (i = 0; i < 6; i++) {
    printf("%d, ", arr[i]);
  }
}
