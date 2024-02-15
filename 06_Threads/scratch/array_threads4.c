/*
*  array_threads4.c: Need to find the sum of an array having 16 integers
*  main thread create four threads, each thread compute sum of 4 elements and place the sum
*  in another array sum[4]. main thread finally sums up the 4 sub-sums and displays
*  the final sum.  
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <math.h>
#include <unistd.h>

#define SIZE 16 
#define MAX_THREAD 4 
int arr[SIZE] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 }; 
int sum[MAX_THREAD] = {0, 0, 0, 0}; 
int thread_no = 0; 
void* sum_array(void*);
int main() { 
	for (int i = 0; i < SIZE; i++) 
		printf("%d ", arr[i]);
	printf("\n");
	pthread_t tids[MAX_THREAD]; 
// Creating 4 threads 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_create(&tids[i], NULL, sum_array, (void*)NULL); 
// joining 4 threads i.e. waiting for all 4 threads to complete 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(tids[i], NULL); 
// adding sum of all 4 parts 
	int total_sum = 0; 
	for (int i = 0; i < MAX_THREAD; i++) 
		total_sum += sum[i]; 
	printf("sum is: %d\n", total_sum);	 
	return 0; 
} 
void* sum_array(void* arg) { 
// Each thread computes sum of 1/4th of array 
	int thread_id = thread_no; thread_no++; 
	for (int i = thread_id * (SIZE / 4); i < (thread_id + 1) * (SIZE / 4); i++) 
		sum[thread_id] += arr[i]; 
} 
