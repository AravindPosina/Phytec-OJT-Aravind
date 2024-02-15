#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <math.h>
#include <unistd.h>

// Value depend on System core 
#define CORE 4 
#define MAX_THREAD 4 
// Maximum matrix size 
#define MAX 4 
int thread_no = 0;
// Maximum threads is equal to total core of system 
pthread_t thread[MAX_THREAD]; 
int mat_A[MAX][MAX], mat_B[MAX][MAX], sum[MAX][MAX]; 

// Addition of a Matrix 
void* addition(void* arg) { 
	int i, j, num = thread_no++;
	//int core = *((int*)arg); 
	// Each thread computes 1/4th of matrix addition 
	for (i = num * MAX / 4; i < (num + 1) * MAX / 4; i++) { 
		for (j = 0; j < MAX; j++) { 
			// Compute Sum Row wise 
			sum[i][j] = mat_A[i][j] + mat_B[i][j]; 
		} 
	} 
} 


// Driver Code 
int main() 
{ 

	int i, j, step = 0; 
	// Generating random values in mat_A and mat_B 
	for (i = 0; i < MAX; i++) { 

		for (j = 0; j < MAX; j++) { 

			mat_A[i][j] = rand() % 10; 
			mat_B[i][j] = rand() % 10; 

		} 

	} 


	// Displaying mat_A 
	fprintf(stderr,"\nMatrix A:\n"); 
	for (i = 0; i < MAX; i++) { 
		for (j = 0; j < MAX; j++) { 
			fprintf(stderr,"%d ", mat_A[i][j]); 
		} 
		fprintf(stderr,"\n"); 
	} 

	// Displaying mat_B 
	fprintf(stderr,"\nMatrix B:\n"); 
	for (i = 0; i < MAX; i++) { 
		for (j = 0; j < MAX; j++) { 
			fprintf(stderr,"%d ", mat_B[i][j]); 
		} 
		fprintf(stderr,"\n"); 
	} 

	// Creating threads equal 
	// to core size and compute matrix row 
	for (i = 0; i < MAX_THREAD; i++) { 
		pthread_create(&thread[i], NULL, &addition, NULL); 
	//	pthread_create(&thread[i + CORE], NULL, &subtraction, (void*)step); 
		step++; 
	} 

	// Waiting for join threads after compute 
	for (i = 0; i < MAX_THREAD; i++) { 
		pthread_join(thread[i], NULL); 
	} 

	// Display Addition of mat_A and mat_B 
	printf("\n Sum of Matrix A and B:\n"); 
	for (i = 0; i < MAX; i++) { 
		for (j = 0; j < MAX; j++) { 
			fprintf(stderr,"%d ", sum[i][j]); 
		} 
		fprintf(stderr,"\n"); 
	} 
	return 0; 
} 


