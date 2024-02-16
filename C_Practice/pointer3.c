#include<stdio.h>

int* increment(int a)
{
    int *b;
    *b = a;
    *b += 1;
    
    return b; 
}

int main()
{
    int num = 5;
    
    int *b = increment(num);
    printf("Incremented value = %d", *b);

    return 0;
}
