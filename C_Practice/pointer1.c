#include<stdio.h> 
void display(void (*p)())  
    {  
        for(int i=1;i<=5;i++)  
        {  
            p(i);  
        }  
    }
    int main( print_numbers)  
    {  
        void (*p)(int);     
        printf("The values are :");  
        display (print_numbers);  
        return 0;  
    }  
