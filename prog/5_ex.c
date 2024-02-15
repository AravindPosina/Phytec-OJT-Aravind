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
   int fd = open ("2_ex.c", O_RDONLY);//file opened in read mode
   int n;
   for(;;)
   {
      n = read (fd, buff, 1000);
      if (n <= 0){
         close(fd);
	 return 0;
      }
      write(1, buff, n);
   }
   return 0;
}
