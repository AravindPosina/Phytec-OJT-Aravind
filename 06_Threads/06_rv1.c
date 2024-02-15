/*
*  rv1.c: The main() receives two numbers via cmd line arg
*  Creates two threads and pass one number to each
*  Each thread computes the nth prime number and the result
*  Finally main thread displays the two prime numbers
*  compile: $ gcc rv1.c -lpthread -lm
*  usage: $./a.out <n1> <n2> 
*/

#include <pthread.h> // Include the pthread library for multithreading.
#include <stdio.h>
#include <stdlib.h>  
#include <math.h>

// Define a function prototype for f1.
void* f1(void *);

int main(int argc, char* argv[]) {
   if (argc != 3) {
      printf("Invalid arguments. Please enter two integers\n");
      exit(1); // Exit the program with an error code if there are not exactly two command-line arguments.
   }
   
   int num1 = atoi(argv[1]); // Convert the first command-line argument to an integer.
   int num2 = atoi(argv[2]); // Convert the second command-line argument to an integer.
   
   pthread_t tid1, tid2; // Declare thread identifiers tid1 and tid2.
   
   // Create two threads that run the f1 function, passing num1 and num2 as arguments.
   pthread_create(&tid1, NULL, f1, (void*)&num1);
   pthread_create(&tid2, NULL, f1, (void*)&num2);
   
   void* rv1, *rv2; // Declare variables to store the return values of the threads.
   
   // Wait for both threads to finish and store their return values in rv1 and rv2.
   pthread_join(tid1, &rv1);
   pthread_join(tid2, &rv2);
   
   // Extract the prime numbers returned by the threads.
   long prime1 = *(long*)rv1;
   long prime2 = *(long*)rv2;
   
   // Print the results.
   printf("\nThe %dth prime number as returned by child thread is: %ld\n", num1, prime1);
   printf("\nThe %dth prime number as returned by child thread is: %ld\n", num2, prime2);
   
   return 0;
}

// Define the f1 function, which calculates prime numbers.
void * f1(void * args) {
   int n = *((int*)args); // Extract the integer argument from the void pointer.
   long *candidate = (long*)malloc(sizeof(long)); // Allocate memory for the candidate prime number.
   *candidate = 2; // Initialize the candidate to 2, the first prime number.
   
   while(1) { // Enter an infinite loop for finding prime numbers.
      long factor;
      int is_prime = 1; // Initialize the is_prime flag to 1 (true).
      
      // Check for factors of the candidate by iterating up to its square root.
      for (factor = 2; factor <= sqrt((*candidate)); ++factor) {
         if ((*candidate) % 2 == 0) { // Check if the candidate is even.
            is_prime = 0; // If it's even, set is_prime to 0 (false) and break.
            break;
         }
         if ((*candidate) % factor == 0) { // Check if factor divides the candidate evenly.
            is_prime = 0; // If it does, set is_prime to 0 (false) and break.
            break;
         }
      } // End of the for loop
      
      if (is_prime == 1) // If is_prime remains 1, the candidate is prime.
         n--; // Decrement the number of prime numbers to find.
      
      if (n == 0) // If n reaches 0, the desired prime number is found.
         pthread_exit((void*)(candidate)); // Exit the thread and return the candidate as the result.
      
      ++(*candidate); // Increment the candidate for the next iteration.
   } // End of the while loop
}

