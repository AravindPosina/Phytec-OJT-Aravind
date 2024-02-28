#include <stdio.h>

int main() {
    int arr[100],size,i;
    printf("enter size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	    printf("Array element %d : ",i+1);
	    scanf("%d",&arr[i]);
    }
    int evenCount = 0, oddCount = 0;

    for ( i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    printf("Number of even elements: %d\n", evenCount);
    printf("Number of odd elements: %d\n", oddCount);

    return 0;
}

