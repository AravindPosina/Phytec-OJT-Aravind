#include <stdio.h>

int main() {
    int arr[14];
    int size, target,i;
    printf("enter size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	    printf("array element %d: ",i+1);
	    scanf("%d",&arr[i]);
    }
    printf("enter the target to delete:");
    scanf("%d",&target);

    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            break;
        }
    }

    if (i < size) {
        for (int j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
    }

    printf("Array after deleting %d: ", target);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

