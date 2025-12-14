#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    sigset_t blocked_set, pending_set;

    sigemptyset(&blocked_set);
    sigaddset(&blocked_set, SIGINT);

    if (sigprocmask(SIG_BLOCK, &blocked_set, NULL) == -1) {
        perror("sigprocmask error");
        return 1;
    }

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");
    sleep(5);

    if (sigpending(&pending_set) == -1) {
        perror("sigpending error");
        return 1;
    }

    if (sigismember(&pending_set, SIGINT)) {
        printf("SIGINT is pending\n");
    } else {
        printf("SIGINT is not pending\n");
    }

    return 0;
}