// C program that creates a thread and passes a message from the main function to the thread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 1 // A macro that defines the number of threads to create

void *thread_function(void *arg){
    int *returnValue = malloc(sizeof(int));
    *returnValue = 143; // Set the return value
    pthread_exit(returnValue);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int *thread_return;

    pthread_create(&threads[0], NULL, thread_function, NULL);
    pthread_join(threads[0], (void **) &thread_return);
    printf("Value returned from thread: %d\n", *thread_return);
    free(thread_return); 
    return 0;
}