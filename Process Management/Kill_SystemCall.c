// Demonstration of kill() System Call
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid; // Variable to hold the process ID

    pid = fork();
    if (pid < 0){
        // If fork fails, print an error message
        printf("Fork failed");
        return -1;
    }
    if (pid == 0){
        // This block is executed by the child process
        // Print a message to indicate the child process is running
        printf("Child process (PID: %d) is running...\n", getpid());

        // The child process will wait indefinitely until it receives a signal
        while(1){
            pause(); // Wait for signals
        }
        // This line will never be reached if the process is terminated by a signal
    } else{ 
        // This block is executed by the parent process

        // Print a message to indicate that the parent process is sending a signal
        printf("Parent process (%d) sending signal to child (%d)\n", getpid(), pid);

        // Send the SIGTERM signal to the child process
        kill(pid, SIGTERM);

        // Wait for the child process to terminate
        wait(NULL);

        // Print a message to indicate that the child process has been terminated
        printf("Parent process:  Child process has been terminated.\n");
    }
}