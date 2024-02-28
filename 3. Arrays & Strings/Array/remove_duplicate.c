#include <stdio.h>

int removeDuplicates(int arr[], int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        int j;
        for (j = 0; j < index; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (j == index) {
            arr[index++] = arr[i];
        }
    }
    return index;
}

int main()
{
    int arr[14],i,size;
    printf("enter size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	printf("Array elements %d: ",i+1);
	scanf("%d",&arr[i]);
    }
    printf("Array with duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    size = removeDuplicates(arr, size);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

