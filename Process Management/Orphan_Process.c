#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/* An orphan process is a child process whose parent process has terminated or finished before the 
child process completes. When the parent process exits or is terminated unexpectedly without properly 
waiting for the child to finish, the OS reassigns the orphaned child process to the init process.
The  init process adopts and manages orphan processes until they complete execution. */

int main(){

    pid_t child_pid = fork();

    if (child_pid == 0){
        // Child process
        printf("Child process: PID = %d\n", getpid());
        sleep(2); // Sleep to ensure the parent process terminates first
        printf("Child process: My parent's PID = %d\n", getppid());
    } else if (child_pid > 0){
        // Parent Process
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent process: Terminating...\n");
    } else{
        printf("Fork failed\n");
        return 1;
    }
    return 0;
}