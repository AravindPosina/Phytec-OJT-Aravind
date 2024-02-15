/*
*  array_threads5.c: Need to find the maximum element of an array having 16 integers main thread create four threads, each thread finds max out of 4 elements and place the max in another array max_num[4]. main thread finally finds the max out of the 4 sub-max and displays  the final max value.  
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <math.h>
#include <unistd.h>

#define SIZE 16 
#define MAX_THREAD 4 
int arr[SIZE] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 300, 64, 110, 220 }; 
int max_num[MAX_THREAD] = {0, 0, 0, 0}; 
int thread_no = 0; 
void* maximum(void*);
int main() {  
	for (int i=0; i<SIZE; i++) 
		printf("%d ", arr[i]);
	printf("\n");
	pthread_t tids[MAX_THREAD]; 
	// creating 4 threads 
	for (int i=0; i<MAX_THREAD; i++) 
		pthread_create(&tids[i], NULL, maximum, (void*)NULL); 
	// joining all 4 threads to complete 
	for (int i=0; i<MAX_THREAD; i++) 
		pthread_join(tids[i], NULL); 

	// Finding max element in an array by individual threads 
	int final_max = 0;
	for (int i=0; i<MAX_THREAD; i++) { 
		if (max_num[i] > final_max) 
			final_max = max_num[i]; 
	} 
	printf("Maximum Element is : %d \n", final_max); 
	return 0; 
} 
void* maximum(void* arg) { 
	int thread_id = thread_no; thread_no++; 
	int sub_max = 0; 
	for (int i = thread_id*(SIZE/4); i < (thread_id+1)*(SIZE/4); i++) { 
		if (arr[i] > sub_max) 
			sub_max = arr[i]; 
	} 
	max_num[thread_id] = sub_max; 
} 



