#include<stdio.h>  
int main()
{  
	int number=50;      
        int *p;    
        int **p2; 
        p=&number;     
        p2=&p;    
        printf("Address of number variable is %x \n",&number);      
        printf("Address of p variable is %x \n",p);      
        printf("Value of *p variable is %d \n",*p);      
        printf("Address of p2 variable is %x \n",p2);      
        printf("Value of **p2 variable is %d \n",*p);      
	return 0;  
}  
