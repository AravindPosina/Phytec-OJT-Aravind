// example for register keyword for its not access the address of cpu 
#include <stdio.h>  
int main()  
{  
	register int a = 0;   
	printf("%p\n",&a);  
}  
