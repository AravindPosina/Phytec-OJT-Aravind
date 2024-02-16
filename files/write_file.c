/* file2.c
   This program reads the file /etc/passwd 
   and displays its contents on the stdout.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> // if you are using constant O_RDONLY
int main()
{
   char buff[2000];
   int fd = open ("output.txt", O_WRONLY);//file opened in read mode
   int n;
   for(;;)
   {
      n =read(fd,buff,1000);
      if (n <= 0)
      {
         close(fd);
	 printf("error in the source file");
	 return 0;
      }
      write(1, buff, n);
   }
   return 0;
}
