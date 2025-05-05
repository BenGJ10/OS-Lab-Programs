// A C program that prints the contents of current working directory using system calls like 
// opendir, readdir, closedir

#include <stdio.h>
#include <dirent.h> // Allows access to directory operations

int main(){

    DIR *dir; // DIR is a structure representing a directory stream
    struct dirent *entry; // dirent is a structure that holds directory entry info.
    // entry -> will point to each file/folder in the directory during traversal

    dir = opendir(".");
    if(dir){
        printf("Contents of the directory: \n");
        while((entry = readdir(dir)) != NULL){
            printf("%s\n", entry->d_name);
        }
        closedir(dir);
        
    }
    return 0;
}

