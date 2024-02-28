#include <stdio.h>

int main() {
    int arr[14];
    int size, target;
    int frequency = 0;
    printf("enter size: ");
    scanf("%d",&size);
    for(int i=0;i<=size;i++)
    {
	    printf("array element %d: ",i+1);
	    scanf("%d",&arr[i]);
    }
    printf("enter target to find : ");
    scanf("%d",&target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            frequency++;
        }
    }

    printf("Frequency of %d in the array: %d\n", target, frequency);

    return 0;
}

