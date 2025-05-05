// A C program to prevent Race condition with Mutex

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_COUNT 1000000

int shared_variable = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_variable(void *thread_id){
    for(int i = 0; i < MAX_COUNT; i++){
        pthread_mutex_lock(&mutex); // Acquires the lock (blocks if already locked)
        shared_variable++; // Safely increments the shared variable (critical section)
        pthread_mutex_unlock(&mutex); // Releases the lock, allowing others to enter
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL); // Explicitly initializes mutex with default attributes

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, increment_variable, (void*)i);
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex); // Destroys the mutex after use to release system resources

    printf("Value of shared variable after synchronization: %d\n", shared_variable);

    return 0;
}