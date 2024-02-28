#include <stdio.h>
int main()
{
  int a, result;
  printf("Enter a number:");
  scanf("%d",&a);
  result = a;
  printf("=a operation = %d\n", result);
  result += a;
  printf("+a operation = %d\n", result);
  result -=a;
  printf("-=a operation = %d\n", result);
  result *= a;		 
  printf("*=a operation = %d\n", result);
  result /= a;	
  printf("/=a operation = %d\n", result);
  return 0;
}
