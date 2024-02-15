/*
*  Lseek for file
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>

int main(){
//create a file and check the value of fd
   remove("f1.txt");
   int fd = open("f1.txt",O_RDWR|O_CREAT|O_TRUNC,0622);
   printf("open() returned fd= %d\n", fd);

//check and print value of cfo
   int cfo = lseek(fd, 0, SEEK_CUR);
   printf("Location of CFO= %d\n", cfo);

//write and check the value of cfo
   write(fd, "abcde", 5);
   cfo = lseek(fd, 0, SEEK_CUR);
   printf("Location of CFO after writing ""abcde""= %d\n", cfo);

//move the cfo 100 bytes ahead the EOF
   lseek(fd, 100, SEEK_END);
   cfo = lseek(fd, 0, SEEK_CUR);
   printf("Location of CFO after lseek(fd, 100, SEEK_END)= %d\n", cfo);

//let us write and check the value of cfo
   write(fd, "ABCDE", 5);
   cfo = lseek(fd, 0, SEEK_CUR);
   printf("Location of CFO after writing ""ABCDE""= %d\n", cfo);
   return 0;
}
