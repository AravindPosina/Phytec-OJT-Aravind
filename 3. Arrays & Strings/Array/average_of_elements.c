#include <stdio.h>

int main() {
    int arr[10],sum=0,size;
    printf("enter size: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
	    printf("Array element %d: ",i+1);
	    scanf("%d",&arr[i]);
    }

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    double average = (double)sum / size;
    printf("Average of array elements: %.2f\n", average);

    return 0;
}

