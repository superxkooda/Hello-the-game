SHELL=/bin/bash
build ?= build
CC = c++
CFLAGS=-g -c -Wall -Iinclude/
vpath %.cpp src:src/titleScreen
vpath %.h include
#what are we compiling
objects=$(build)/main.o $(build)/myLib.o\
$(build)/titleScreen.o 

all:$(build)/bin/hello

build:
	@mkdir -v $(build) 
	@mkdir -v  $(build)/bin

$(build)/bin/hello:$(objects)
	$(CC) $(build)/*.o -o $@ -lcurses
		
$(objects): $(build)/%.o:%.cpp| build 
	 $(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	@rm -rv $(build) 

install:
	cp -vi ./$(build)/bin/hello /usr/bin/hello

uninstall:
	rm -vi /usr/bin/hello
