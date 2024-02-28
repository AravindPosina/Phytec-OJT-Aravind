#include <stdio.h>

int cube(int num);

int main()
{
    int num;
    int c;
    printf("Enter any number: ");
    scanf("%d", &num);
    
    c = cube(num);

    printf("Cube of %d is %d\n", num, c); 
    
    return 0;
}
int cube(int num)
{
    return (num * num * num);
}

