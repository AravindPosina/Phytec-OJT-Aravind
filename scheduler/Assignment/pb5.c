#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg) {
    for (int i = 0; i < 5; i++) {
        // Simulate work
        for (volatile int j = 0; j < 1000000; j++) {}
        printf("Thread %d: Iteration %d\n", *((int *)arg), i);
        sched_yield(); // Yield the CPU voluntarily
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int thread1_id = 1;
    int thread2_id = 2;

    pthread_create(&thread1, NULL, thread_func, &thread1_id);
    pthread_create(&thread2, NULL, thread_func, &thread2_id);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

