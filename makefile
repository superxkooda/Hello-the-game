#first makefile
CC = c++
flags= -g -c -Wall -Iinclude/ 
vpath %.h  include
all: convo

convo: cpp 
	$(shell scripts/dirs.sh)
	$(CC) *.o -o ./build/bin/hello -lcurses 
	mv -v *.o ./build

cpp:
	$(CC) $(flags) src/*.cpp
	$(CC) $(flags) src/titleScreen/titleScreen.cpp


clean: 
	rm -rfv ./build

install:
	cp -vi ./build/bin/hello /usr/bin/hello

uninstall:
	rm -vi /usr/bin/hello
