dir = $(shell pwd)
src = $(dir)/src
obj = $(dir)/obj
lib = $(dir)/lib
bin = $(dir)/bin
include = $(dir)/include

CC = gcc
AR = ar

myapp = $(bin)/myapp
liba = $(lib)/libmybasic.a

.PHONY: all clean basic

all: $(myapp)

$(myapp): $(liba) $(obj)/myapp.o
	$(CC) -o $@ $^ -L$(lib) -lmybasic -I$(include)


basic: $(liba)

$(obj)/%.o: $(src)/%.c 
	$(CC) -c $< -o $@ -I$(include)

$(liba): $(obj)/add.o $(obj)/sub.o $(obj)/mul.o $(obj)/div.o
	$(AR) rcs $@ $^

clean:
	rm -f $(obj)/*.o $(lib)/*.a $(bin)/*
