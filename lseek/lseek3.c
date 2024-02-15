/*
* Lseek for file with holes
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
   int holes = atoi(argv[1]);
	int fd = open("filewithholes.txt",O_CREAT|O_WRONLY|O_TRUNC, 0644);
	//write(fd, "PHYTEC", 5);
	for(int i = 0; i < holes; i++){
		lseek(fd, 10, SEEK_CUR);
		write(fd, "PHYTEC", 6);
	}
	close(fd);
   return 0;
}
