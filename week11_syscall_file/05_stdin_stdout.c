#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>

#define BUFFER_SIZE 128

int main(int argc, char *argv[]){
    
    if(argc != 1){
        printf("Usage: %s\n", argv[0]);
        return 1;    
    }
    char * readStr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    int read_result;
    while(1){
    int n = read(STDIN_FILENO, readStr, BUFFER_SIZE);
        if (n == 0) {
            printf("표준 입력 종료\n");
            break;
        }
        if (n == -1) {
            perror("read 실패");
            return 1;
        }
        ssize_t written = 0;
        while (written < n) {
            ssize_t w = write(STDOUT_FILENO, readStr + written, n - written);
            if (w == -1) {
                perror("write 실패");
                return 1;
            }
            written += w;
        }
    }
    free(readStr);
    return 0;
}