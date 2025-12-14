#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void sigint_hadler (int sig){
    printf("[sigint handler] ----------------\n");
    pid_t child_pid;
    
    child_pid = fork();
    if(child_pid == 0){
        execve("/usr/bin/ls",NULL, NULL);
        exit(1);
    }
    else{ 
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Child exited with status: %d\n",WEXITSTATUS(wstatus));
        }
    }
    return;
}

void sigquit_handler (int sig){
    printf("[sigquit handler] ----------------\n");
    pid_t child_pid;
    
    child_pid = fork();
    if(child_pid == 0){
        execve("/usr/bin/date",NULL , NULL);
        exit(1);
    }
    else{ 
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Child exited with status: %d\n",WEXITSTATUS(wstatus));
        }
    }
    return;
}

void sigalrm_handler (int sig){
    printf("[sigalrm handler] ----------------\n");
    pid_t child_pid;
    
    child_pid = fork();
    if(child_pid == 0){
        execve("/usr/bin/whoami",NULL , NULL);
        exit(1);
    }
    else{ 
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Child exited with status: %d\n",WEXITSTATUS(wstatus));
        }
        alarm(3);
    }
    return;
}

int main(){

    struct sigaction sa_int;
    sa_int.sa_handler = sigint_hadler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);

    struct sigaction sa_quit;
    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;
    sigaction(SIGQUIT, &sa_quit, NULL);

    struct sigaction sa_alrm;
    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;
    sigaction(SIGALRM, &sa_alrm, NULL);

    alarm(3);
    for(;;){
        sleep(1);
    }




}