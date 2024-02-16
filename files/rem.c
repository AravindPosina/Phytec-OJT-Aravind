#include <stdio.h>    
     
int main()    
{    
    int num = 156;    
    int rem = 0, sum = 0, n,mul =1;    
        
    //Make a copy of num and store it in variable n    
    n = num;    
        
    //Calculates sum of digits    
    while(num > 0){    
        rem = num%10;    
        mul = mul *rem;
	sum = sum + rem;    
        num = num/10;    
	
    }   

   printf("the given numbersum :%d\n",sum);
   printf("the given number multiple :%d\n",mul);
} 
