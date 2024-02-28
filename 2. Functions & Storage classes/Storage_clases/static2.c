#include <stdio.h>

void function() {
    static int a = 0; 
    a++;
    printf("value : %d\n", a);
}

int main() 
{
    function();
    function(); 
    function(); 
}

