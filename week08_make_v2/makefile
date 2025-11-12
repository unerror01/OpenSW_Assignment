dir = $(shell pwd)
src = $(dir)/src
obj = $(dir)/obj
lib = $(dir)/lib
bin = $(dir)/bin
include = $(dir)/include
LDFLAGS = -L$(lib) -lmybasic -lmyadvanced



CC = gcc
AR = ar

myapp = $(bin)/myapp
Libs = $(lib)/libmybasic.a $(lib)/libmyadvanced.a

.PHONY: all clean basic_ops advanced_ops

all: basic_ops advanced_ops $(myapp)

$(myapp): $(Libs) $(src)/myapp.c
	$(CC) -o $@ $^ $(LDFLAGS) -I$(include)


basic_ops:
	make -C basic_ops

advanced_ops:
	make -C advanced_ops

clean:
	rm -f $(obj)/*.o $(bin)/*
	make -C basic_ops clean
	make -C advanced_ops clean
