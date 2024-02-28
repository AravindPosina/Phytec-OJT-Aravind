#include <stdio.h>
int main() 
{
	int a,b,result = 0;      	 
	printf("Enter 1st number:");
	scanf("%d",&a);
	printf("Enter 2nd number:");
	scanf("%d",&b);

	result = a & b;   	
	printf("Binary AND Operator of a and b is %d\n", result );
	result = a ^ b;   	
	printf("Binary XOR Operator of a and b is %d\n", result );
	result = ~a;      	
	printf("Binary Ones Complement Operator of a is %d\n", result );
	result = a << 2; 	
	printf("Binary Left Shift Operator of a is %d\n", result );
	result = a >> 2; 	
	printf("Binary Right Shift Operator of a is %d\n", result );
}
