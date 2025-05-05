// A C program to demonstrate the use of getcwd, mkdir, chdir, rmdir System Calls

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define NEW_DIR "New_Directory"

int main(){
    char cwd[1024]; // Buffer to store current working directory

    // Get the current working directory
    if(getcwd(cwd, sizeof(cwd)) == NULL){ // Gets absolute path of current directory and stores it in cwd
        printf("Error getting current working directory\n");
        return -1;
    }
    printf("Original Working Directory: %s\n", cwd);

    // Create a new_directory
    if(mkdir(NEW_DIR, 0755) != 0){ // Creates a new directory with name "New_Directory" and permissions 0755
        printf("Error creating new directory\n");
        return -1;
    }
    
    // Change to the new_directory
    if(chdir(NEW_DIR) != 0){
        printf("Error changing to new directory");
        return -1;
    }

    // Print the new working directory
    if(getcwd(cwd, sizeof(cwd)) == NULL){
        printf("Error getting new working directory\n");
        return -1;
    }
    printf("New working directory: %s\n", cwd);

    // Changing back to the original directory
    if(chdir("..") != 0){ // chdir("..") moves up one directory
        printf("Error changing back to original directory\n");
        return -1;
    }

    // Remove the new directory
    if(rmdir(NEW_DIR) != 0){
        printf("Error removing new directory\n");
        return -1;
    }

    printf("Removed directory %s and changed back to original directory\n", NEW_DIR);
}