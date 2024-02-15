#include <stdio.h>
#include <pthread.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int buffer_count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    for (int i = 0; i < 10; i++) {
        // Produce an item (in this case, an integer)
        int item = i + 1;

        pthread_mutex_lock(&mutex);

        while (buffer_count == BUFFER_SIZE) {
            // Buffer is full, wait for the consumer to consume
            pthread_cond_wait(&empty, &mutex);
        }

        // Place the item in the buffer
        buffer[buffer_count] = item;
        buffer_count++;

        printf("Produced: %d\n", item);

        // Signal the consumer that the buffer is not empty anymore
        pthread_cond_signal(&empty);

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);

        while (buffer_count == 0) {
            // Buffer is empty, wait for the producer to produce
            pthread_cond_wait(&empty, &mutex);
        }

        // Consume an item from the buffer
        int item = buffer[buffer_count - 1];
        buffer_count--;

        printf("Consumed: %d\n", item);

        // Signal the producer that the buffer is not full anymore
        pthread_cond_signal(&empty);

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}

