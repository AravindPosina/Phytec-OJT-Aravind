#include <stdio.h>
int findOddOccurring(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}
int main() {
    int arr[] = {4, 2, 2, 1, 5, 6, 7, 5, 6, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int oddOccurringNumber = findOddOccurring(arr, n);
    printf("The odd occurring number is: %d\n", oddOccurringNumber);
    return 0;
}

