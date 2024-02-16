#include<stdio.h>
#include<malloc.h>

struct OurArray
{
  int array[5];
};

struct OurArray getArray()
{
  struct OurArray arr;
  int i;

  printf("Enter 5 elements \n");
  for (i = 0; i < 5; i++)
  {
    scanf("%d", & arr.array[i]);
  }
  return arr;
}

void main() 
{
  struct OurArray arr = getArray();
  int i;
  printf("Five elements of array are = ");
  for (i = 0; i < 5; i++) {
    printf("%d, ", arr.array[i]);
  }
}
