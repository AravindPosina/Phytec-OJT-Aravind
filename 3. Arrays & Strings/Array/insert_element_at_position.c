#include <stdio.h>

int main() {
    int arr[14],i;
    int size,element,position;
    printf("enter size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	    printf("Array element %d: ",i+1);
	    scanf("%d",&arr[i]);
    }
    printf("enter position to insert: ");
    scanf("%d",&position);
    printf("Enter element to insert: ");
    scanf("%d",&element);
    if (position < 0 || position > size) {
        printf("Invalid position\n");
        return 0;
    }

    for ( i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;

    printf("Array after inserting %d at position %d: ", element, position);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

