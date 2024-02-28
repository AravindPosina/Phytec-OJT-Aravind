#include <stdio.h>
int main()
{
  int j = 6, t = 4;
  printf("Enter 1st number:");
  scanf("%d",&j);
  printf("Enter 2nd number:");
  scanf("%d",&t);


  printf("%d == %d is %d \n", j, t, j == t);
  printf("%d > %d is %d \n", j, t, j > t);
  printf("%d < %d is %d \n", j, t, j < t);
  printf("%d != %d is %d \n", j, t, j != t);
  printf("%d >= %d is %d \n", j, t, j >= t);
  printf("%d <= %d is %d \n", j, t, j <= t);

  return 0;
}
