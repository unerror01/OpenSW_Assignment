#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


struct two_double
{
    double a;
    double b;
} data;


void sigint_hadler (int sig){
    printf("%f , %f\n", data.a, data.b);
    alarm(1);
}

int main(){

    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};


    sa_sigalrm.sa_handler = sigint_hadler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;

    if(sigaction(SIGALRM, &sa_sigalrm, NULL) == -1){
        perror("sigaction error: ");
        exit(0);
    }   
    sigset_t block_mask;
    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGALRM);

    alarm(1);
    for(;;){
        //block SIGALRM
        sigprocmask(SIG_BLOCK, &block_mask, NULL); 
        data = ones;
        // unblock SIGALRM
        sigprocmask(SIG_UNBLOCK, &block_mask, NULL);

        sigprocmask(SIG_BLOCK, &block_mask, NULL);
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &block_mask, NULL);
    }
}