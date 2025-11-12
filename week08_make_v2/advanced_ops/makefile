dir = $(shell pwd)
src = $(dir)/src
obj = $(dir)/obj


TOP = $(dir)/..
lib = $(TOP)/lib
bin = $(TOP)/bin
include = $(TOP)/include

CC = gcc
AR = ar

liba = $(lib)/libmyadvanced.a
OBJS = $(obj)/mymod.o $(obj)/mypow.o

.PHONY: all clean

all: $(liba)


$(obj)/%.o: $(src)/%.c | $(obj)
	$(CC) -c $< -o $@ -I$(include)

$(liba): $(OBJS)
	$(AR) rcs $@ $^

clean:
	rm -f $(obj)/*.o $(liba)
