#include <stdio.h>

int main() {
    int arr[14],i,size;
    printf("enter size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	    printf("Array element %d: ",i+1);
	    scanf("%d",&arr[i]);
    }
    int temp;

    for (int i = 0, j = size - 1; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
