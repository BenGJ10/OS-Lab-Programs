#include <stdio.h>
#include <unistd.h>

int main(){
    
    pid_t child_pid; // Process PID -> A unique number assigned to each process

    // Create a child process
    child_pid = fork();

    if (child_pid == 0){
        // The child process code section
        printf("Child Process: PID = %d\n", getpid());
    } else if (child_pid > 0){
        // The parent process code section
        printf("Parent Process: Child PID = %d\n", child_pid);
    } else{
        // Fork failed
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}

// Different Process States: new, ready, running, blocked, terminated

// Process Table: A data strcture in OS that tracks all running processes
