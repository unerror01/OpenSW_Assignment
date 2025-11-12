dir = $(shell pwd)
src = $(dir)/src
obj = $(dir)/obj


TOP = $(dir)/..
lib = $(TOP)/lib
bin = $(TOP)/bin
include = $(TOP)/include

CC = gcc
AR = ar

liba = $(lib)/libmybasic.a
OBJS = $(obj)/add.o $(obj)/sub.o $(obj)/mul.o $(obj)/div.o

.PHONY: all clean

all: $(liba)


$(obj)/%.o: $(src)/%.c | $(obj)
	$(CC) -c $< -o $@ -I$(include)

$(liba): $(OBJS)
	$(AR) rcs $@ $^

clean:
	rm -f $(obj)/*.o $(liba)
