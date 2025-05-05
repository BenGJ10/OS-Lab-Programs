// A C program to avoid Race condition with Semaphore
// A semaphore is a counter-based synchronization tool used to control access to one or more resources

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5
#define MAX_COUNT 1000000

int shared_variable = 0;
sem_t semaphore;

void *increment_variable(void *thread_id){
    for(int i = 0; i < MAX_COUNT; i++){
        sem_wait(&semaphore); // Decreases the semaphore value, if the value becomes < 0, the thread is blocked (waits)
        shared_variable++; // Critical Section - only one thread can execute this at a time
        sem_post(&semaphore); // Increases the semaphore, unlocks the critical section for another thread
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    
    sem_init(&semaphore, 0, 1);
    /* &semaphore: address of the semaphore
       0: means semaphore is shared between threads (not between processes)
       1: initial value of the semaphore (binary semaphore) */

    for(int i = 0; i < NUM_THREADS; i++){
        // Creates NUM_THREADS threads, all executing the same function
        pthread_create(&threads[i], NULL, increment_variable, (void*) i);
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL); // Waits for all threads, ensures main doesn't finish early
    }

    sem_destroy(&semaphore); // Destroying semaphore

    printf("Value of shared variable after synchronization: %d\n", shared_variable);
    return 0;
}