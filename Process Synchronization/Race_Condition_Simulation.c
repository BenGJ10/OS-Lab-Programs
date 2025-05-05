/*
 Race Condition - a situation where multiple processes or threads tries to work on shared data or
 critical sections without proper synchronization leading to unpredictable and undesirable outcomes. 
*/ 

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5 // Create 5 threads
#define MAX_COUNT 1000000 // Each thread will increment the shared variable 1 million times 

int shared_variable = 0;

void *increment_variable(void *thread_id){
    for(int i = 0; i < MAX_COUNT; i++){
        // Each thread runs this loop MAX_COUNT times, incrementing the shared variable
        shared_variable++;
    }
    pthread_exit(NULL); // Terminates the thread gracefully
}

int main(){
    pthread_t threads[NUM_THREADS]; // Declares an array to store 5 thread identifiers

    for(int i = 0; i < NUM_THREADS; i++){
        // Creates NUM_THREADS threads, all executing the same function
        pthread_create(&threads[i], NULL, increment_variable, (void*) i);
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL); // Waits for all threads, ensures main doesn't finish early
    }

    printf("Value of shared variable after race condition: %d\n", shared_variable);

    return 0;
}