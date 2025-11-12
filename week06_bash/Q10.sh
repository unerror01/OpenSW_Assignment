#!/bin/bash

print_param(){
    echo "script_name: $0"
    echo "first_param: $1"
    echo "second_param: $2"
    echo "all_params: $*"
    echo "the number of params: $#"
}

print_param("Hello" "World" "!")