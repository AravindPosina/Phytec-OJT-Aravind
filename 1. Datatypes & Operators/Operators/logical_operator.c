#include <stdio.h>
int main()
{
  int i = 5, j = 5, k = 10, final;
  printf("Enter 1st number:");
  scanf("%d",&i);
  printf("Enter 2nd number:");
  scanf("%d",&j);
  printf("Enter 3rd number:");
  scanf("%d",&k);

  printf("(i == j) && (k > j) is %d \n", (i == j) && (k > j));

  printf(" (i == j) || (k < j) is  %d \n", (i == j) || (k < j));

  printf(" (i != j) || (k < j) is %d \n", (i != j) || (k < j));

  return 0;
}
