/*
*  rv2.c: The main() receives two file names via cmd line arg
*  Creates two threads and pass each a filename
*  Each thread computes and return the number of characters in the file
*  Finally main thread displays the character count
*  compile: $ gcc rv2.c -lpthread
*  usage: $./a.out <file1> <file2> 
*/

#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Define the function prototype for f1.
void* f1(void * arg);

int main(int argc, char* argv[]){
   if(argc != 3){
      printf("Invalid number of arguments. Must pass two file names.\n");
      exit(1); // Exit the program with an error code if there are not exactly two command-line arguments.
   }

   pthread_t tid1, tid2; // Declare thread identifiers tid1 and tid2.
   void *rv1, *rv2; // Declare variables to store the return values of the threads.
   
   // Create two threads that run the f1 function, passing the file names as arguments.
   pthread_create(&tid1, NULL, f1, (void*)argv[1]);
   pthread_create(&tid2, NULL, f1, (void*)argv[2]);
   
   // Wait for both threads to finish and store their return values in rv1 and rv2.
   pthread_join(tid1, &rv1);
   pthread_join(tid2, &rv2);
   
   // Extract the character count returned by the threads.
   int count1 = *((int*)rv1);
   int count2 = *((int*)rv2);
   
   // Print the character counts for each file.
   printf("Characters in %s: %d\n", argv[1], count1);
   printf("Characters in %s: %d\n", argv[2], count2);
   
   return 0;
}

// Define the f1 function, which counts the characters in a file.
void* f1(void* args){
   char* filename = (char*)args; // Extract the filename from the argument.
   int *result = (int*)malloc(sizeof(int)); // Allocate memory to store the character count.
   *result = 0; // Initialize the character count to 0.
   char ch;
   
   int fd = open(filename, O_RDONLY); // Open the file for reading.
   
   while((read(fd, &ch, 1)) != 0){ // Read the file character by character until the end.
	   (*result)++; // Increment the character count for each character.
   }
   
   close(fd); // Close the file.
   pthread_exit((void*)result); // Exit the thread and return the character count as the result.
}

