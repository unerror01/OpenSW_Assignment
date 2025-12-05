#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

    if(argc < 2){
        printf("Usage: ./03_execve <program path> [OPTION]...\n");
        return 1;
    }

    pid_t child_pid;
    
    child_pid = fork();
    if(child_pid == 0){
        execve(argv[1], &argv[1], NULL);
        exit(1);
    }
    else{ 
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Child exited with status: %d\n",WEXITSTATUS(wstatus));
        }
    }
    return 0;
}