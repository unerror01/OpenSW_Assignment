pwd = $(shell pwd)
cc = gcc
ln = ln -sf

obj = $(pwd)/obj
src = $(pwd)/src
incl =$(pwd)/include
bin = $(pwd)/bin
lib = $(pwd)/lib

inclu = -I$(incl)
libmyops = $(lib)/libmyops
libopt = -L$(lib) -lmyops
option = -shared -fPIC


myapp = myapp

opssrc = $(wildcard $(src)/*.c)
opsobj = $(subst $(src)/,$(obj)/,$(subst .c,.o,$(opssrc)))
opsobj := $(subst $(obj)/myapp.o,,$(opsobj))

.PHONY: all clean

all: $(myapp)

$(obj)/%.o: $(src)/%.c | $(obj)
	$(cc) -c $< -o $@ $(inclu)
	

$(libmyops).so.1.0: $(opsobj) | $(lib)
	$(cc) $(option) $^ -o $@

$(libmyops).so.1:
	$(ln) $(libmyops).so.1.0 $@

$(libmyops).so:
	$(ln) $(libmyops).so.1 $@

$(myapp): $(src)/$(myapp).c $(libmyops).so.1.0 $(libmyops).so.1 $(libmyops).so  | $(bin)
	$(cc) $(src)/$(myapp).c $(inclu) -L$(lib) $(libopt) -o $(bin)/$(myapp)

clean:
	rm -rf $(obj)/* $(bin)/* $(lib)/*
