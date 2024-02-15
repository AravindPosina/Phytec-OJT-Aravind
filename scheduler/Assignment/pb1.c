#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

void *thread_func(void *arg) {
    int policy;
    struct sched_param param;
    pthread_getschedparam(pthread_self(), &policy, &param);

    printf("Thread ID: %lu, Scheduling Policy: %s, Priority: %d\n",
           pthread_self(), (policy == SCHED_FIFO) ? "SCHED_FIFO" : "SCHED_RR", param.sched_priority);

    // Simulate CPU-bound task
    for (int i = 0; i < 100000000; i++) {
        // Do some computation
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    struct sched_param param1, param2;

    // Create thread with SCHED_FIFO policy and priority 1
    param1.sched_priority = 1;
    pthread_setschedparam(pthread_self(), SCHED_FIFO, &param1);
    pthread_create(&thread1, NULL, thread_func, NULL);

    // Create thread with SCHED_RR policy and priority 2
    param2.sched_priority = 2;
    pthread_setschedparam(pthread_self(), SCHED_RR, &param2);
    pthread_create(&thread2, NULL, thread_func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

