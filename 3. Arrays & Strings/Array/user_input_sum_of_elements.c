#include <stdio.h>

int main() {
    int a[14];
    int size;
    printf("enter size: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
	    printf("array element %d :",i+1);
	    scanf("%d",&a[i]);
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}

