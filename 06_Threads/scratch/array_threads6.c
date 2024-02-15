/*
*  array_threads6.c: Need to find the sum of two matrices of size 3x4. main thread create rows number of threads. i.e., three, each thread is responsible to compute the sum row of the resultant matrix sum. main thread finally display the sum matrix. 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <math.h>
#include <unistd.h>

#define MAX_THREAD 3 
#define ROWS 3
#define COLS 4 
int thread_no = 0;
int mat_A[ROWS][COLS] = {1,2,3,4,1,6,3,2,9,2,3,4};
int mat_B[ROWS][COLS] = {5,4,6,2,4,1,2,1,0,7,5,2};
int sum[ROWS][COLS]; 
void* addition(void*);
int main() { 
	int i, j; 
	// Displaying mat_A 
	fprintf(stderr,"\nMatrix A:\n"); 
	for (i = 0; i < ROWS; i++) { 
		for (j = 0; j < COLS; j++) { 
			fprintf(stderr,"%d ", mat_A[i][j]); 
		} 
		fprintf(stderr,"\n"); 
	} 
	// Displaying mat_B 
	fprintf(stderr,"\nMatrix B:\n"); 
	for (i = 0; i < ROWS; i++) { 
		for (j = 0; j < COLS; j++) { 
			fprintf(stderr,"%d ", mat_B[i][j]); 
		} 
		fprintf(stderr,"\n"); 
	} 

	// Creating 4 threads 
	pthread_t tids[MAX_THREAD]; 
	for (i = 0; i < MAX_THREAD; i++) 
		pthread_create(&tids[i], NULL, &addition, (void*)NULL); 
	// Waiting for join threads after compute 
	for (i = 0; i < MAX_THREAD; i++)
		pthread_join(tids[i], NULL);

	// Display Addition of mat_A and mat_B 
	printf("\n Sum of Matrix A and B:\n"); 
	for (i = 0; i < ROWS; i++) { 
		for (j = 0; j < COLS; j++) { 
			fprintf(stderr,"%d ", sum[i][j]); 
		} 
		fprintf(stderr,"\n"); 
	} 
	return 0; 
} 

void* addition(void* arg) { 
	int thread_id = thread_no; thread_no++;
		for (int j = 0; j < COLS; j++) { 
			sum[thread_id][j] = mat_A[thread_id][j] + mat_B[thread_id][j]; 
		} 
} 
