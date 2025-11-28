#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <error.h>

#define BUFFER_SIZE 32

int main(int argc, char *argv[]){
    
    if(argc < 2){
        printf("Usage: %s <source_file> [destination_file1] [destination_file2] ...\n", argv[0]);
        return 1;    
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("소스 파일 열기 실패");
        return 1;
    }

    int num_file = argc - 2;
    int * dest_fd_list = (int *)malloc(sizeof(int) * num_file);
    for(int i = 0; i < num_file; i++){
        dest_fd_list[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC , 0644);
        if (dest_fd_list[i] == -1) {
            perror("대상 파일 열기 실패");
            close(src_fd);
            return 1;
        }
    }
    char* readStr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    int read_result;
    while(1){
        int n = read(src_fd, readStr, BUFFER_SIZE);
        if (n == 0) {
            printf("파일 복사 완료\n");
            break;
        }
        if (n == -1) {
            perror("read 실패");
            close(src_fd);
            for(int i = 0; i < num_file; i++){
                close(dest_fd_list[i]);
            }
            return 1;
        }
        for(int i = 0; i < num_file; i++){
            ssize_t written = 0;
            while (written < n) {
                ssize_t w = write(dest_fd_list[i], readStr + written, n - written);
                if (w == -1) {
                    perror("write 실패");
                    close(src_fd);
                    return 1;
                }
                written += w;
            }
        }
    }
    free(readStr);
    close(src_fd);
    for(int i = 0; i < num_file; i++){
        close(dest_fd_list[i]);
    }
    free(dest_fd_list);
    return 0;
}
