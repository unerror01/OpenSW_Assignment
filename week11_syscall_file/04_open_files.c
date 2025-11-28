#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    if (argc < 2) {
        printf("파일을 더 입력하세요\n");
        return 1;
    }

    int file_count = argc - 1;
    int * file_list = (int *)malloc(file_count * sizeof(int));
    int * open_file = (int *)malloc(sizeof(int) * file_count);

    for(int i = 0; i < file_count; i++){
        file_list[i] = open(argv[i + 1], O_RDONLY);
        if (file_list[i] == -1) {
            perror("파일 열기 실패");

            open_file[i] = 0;
        } else {
            printf("파일[%d] 열기 성공: %s\n", i, argv[i + 1]);
            open_file[i] = 1;
        }
    }
    for(int i = 0; i < file_count; i++){
        if (open_file[i]) {
            printf("파일[%d] 닫는 중: %s\n", i, argv[i + 1]);
            close(file_list[i]);
        }
    }
    free(file_list);
    free(open_file);
    return 0;
}