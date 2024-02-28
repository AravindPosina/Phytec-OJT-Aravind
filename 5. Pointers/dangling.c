#include <stdio.h>  
int main()  
{  
   int *ptr=(int *)malloc(sizeof(int));  
   int a=560;  
   ptr=&a;  
   free(ptr);  
   return 0;  
}  
