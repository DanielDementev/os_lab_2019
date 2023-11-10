#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id=fork();// create a child process

    if(id==0)
    {
        printf("Это дочерний процесс\n");
        exit(0);
    }
    else{
        sleep(3);
        printf("Родительский процесс\n");
    }
    
    return 0;
}