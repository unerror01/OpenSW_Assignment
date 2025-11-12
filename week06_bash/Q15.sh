# !/bin/bash

file_wordcnt(){

    if [ ! -r $1 ]; then
        echo "$1 파일이 존재 하지 않습니다."
        return 1
    fi

    echo "$1 파일의 단어는 $(wc -w < $1)개 입니다."
}

read -p "Enter file name: " FILE
file_wordcnt $FILE
echo "file_wordcnt 함수의 종료 상태: $?"