#include <stdio.h>  
int main()  
{  
	int a = 10,i;   
	printf("%d ",a++);  
	{  
		int a = 20;   
		for (i=0;i<3;i++)  
		{  
			printf("%d ",a);  
		}  
	}  
	printf("%d\n ",a);    
}  
