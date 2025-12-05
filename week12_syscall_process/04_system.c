#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int mysystem(char * cmd){

    pid_t child_pid;
    child_pid = fork();

    if(child_pid == 0){
        execl("/bin/sh", "sh", "-c", cmd, (char *) NULL);
    }
    else{
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
    }


    return 0;
}

int main(){

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");
    printf("Good bye~\n");

    return 0;
}