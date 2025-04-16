// C program that creates a thread with NULL attributes

#include <stdio.h>
#include <pthread.h> // provides functions and types necessary to create and manage threads

void *thread_function(void *arg){
    // void * -> generic pointer, meaning it can point to any data type
    printf("Inside the new thread!\n");
    return NULL;
}

int main(){
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}