#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include<errno.h>
#include<fcntl.h>
#define N 5  // Total number of waiting room chairs

sem_t barberReady;
sem_t accessWRSeats;
sem_t custReady;
int numberOfFreeWRSeats = N;

void *Barber(void *arg) {
    while (1) {
        sem_wait(&custReady);  // Try to acquire a customer - if none is available, go to sleep.
        sem_wait(&accessWRSeats);  // Awake - try to get access to modify the number of available seats, otherwise sleep.
        numberOfFreeWRSeats += 1;  // One waiting room chair becomes free.
        sem_post(&barberReady);  // I am ready to cut.
        sem_post(&accessWRSeats);  // Don't need the lock on the chairs anymore.
        // (Cut hair here.)
        printf("Barber is cutting hair.\n");
        sleep(1);  // Simulate cutting hair.
    }
}

void *Customer(void *arg) {
    while (1) {
        sem_wait(&accessWRSeats);  // Try to get access to the waiting room chairs.
        if (numberOfFreeWRSeats > 0) {
            numberOfFreeWRSeats -= 1;  // Sit down in a chair.
            sem_post(&custReady);  // Notify the barber, who's waiting until there is a customer.
            sem_post(&accessWRSeats);  // Don't need to lock the chairs anymore.
            sem_wait(&barberReady);  // Wait until the barber is ready.
            // (Have hair cut here.)
            printf("Customer is having a haircut.\n");
            sleep(1);  // Simulate the haircut.
        } else {
            sem_post(&accessWRSeats);  // Release the lock on the seats if there are no free seats.
            // (Leave without a haircut.)
            printf("Customer left without a haircut.\n");
            sleep(1);  // Simulate leaving.
        }
    }
}

int main() {
    pthread_t barberThread, customerThreads[N];

    sem_init(&barberReady, 0, 0);
    sem_init(&accessWRSeats, 0, 1);
    sem_init(&custReady, 0, 0);

    pthread_create(&barberThread, NULL, Barber, NULL);

    for (int i = 0; i < N; i++) {
        pthread_create(&customerThreads[i], NULL, Customer, NULL);
    }

    pthread_join(barberThread, NULL);

    return 0;
}

