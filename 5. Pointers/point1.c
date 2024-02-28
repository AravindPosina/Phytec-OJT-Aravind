#include <stdio.h>

int main() {
    int num = 10;
    int *ptr; 

    ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value pointed to by ptr: %d\n", *ptr); 
    printf("Address stored in ptr: %p\n", ptr);

    *ptr = 20;

    printf("New value of num: %d\n", num);

    return 0;
}

