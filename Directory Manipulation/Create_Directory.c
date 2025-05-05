// A C program to create a new directory within the file system

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    const char *dirname = "New_Directory";
    mkdir(dirname, 0777);

    return 0;
}