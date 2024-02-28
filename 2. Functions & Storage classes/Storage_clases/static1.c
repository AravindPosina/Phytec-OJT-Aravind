//example for static its 
#include<stdio.h>  
void sum() ; 
void main()  
{  
	int i;  
	for(i = 0; i< 3; i++)  
	{  
		sum();
	}  
}  
void sum()  
{   
        static int a = 10;
        static int b = 24;
        printf("%d %d \n",a,b);
        a++;
        b++;
} 
