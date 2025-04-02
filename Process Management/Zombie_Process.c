#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/* A zombie process is a terminated process that has completed its execution but still has an entry 
in the process table. After a process completes, it sends an exit status to its parent process and
becomes a zombie waiting for the parent to retrieve the exit status using the wait() system call.
If the parent fails to fetch the exit status of the terminated child, the zombie process remains
in the process table as an inactive process entry. */

int main(){

    pid_t child_pid = fork();

    if (child_pid == 0){
        // Child process
        printf("Child process: PID = %d\n", getpid());
        exit(0); // Child process exits immediately
    } else if (child_pid > 0){
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent process: Child PID = %d\n", child_pid);
        sleep(10); // Sleep to allow time for the child to become a zombie process
        printf("Parent process: Terminating...\n");
    } else{
        printf("Fork failed\n");
        return 1;
    }
    return 0;
}