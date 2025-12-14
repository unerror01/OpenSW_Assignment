#include <stdio.h>
#include <unistd.h>

int main() {

    for(;;){
        
        printf("pid: %lu\n", (unsigned long)getpid());
        sleep(1);
    }

    return 0;
}