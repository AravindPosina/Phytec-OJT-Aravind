#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
   int flags;
   int fd = open("abc.txt", O_RDWR);
   char input[100];
   printf("Enter a string: ");
   fgets(input, sizeof(input), stdin);
   write(fd, input, strlen(input));
   flags = fcntl(fd, F_GETFL, 0);
   flags = flags |O_APPEND;
   fcntl(fd, F_SETFL, flags);
   write(fd, input, strlen(input));

   return 0;
}
