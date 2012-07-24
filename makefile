#first makefile
CC = c++
flags=-c -Wall
all: convo

convo: cpp 
	if [ ! -d build -a ! -d build/bin ];	then echo creating build directory;	mkdir -p build/bin;	fi;
	$(CC) *.o -o ./build/bin/hello -lcurses 
	mv -v *.o ./build

cpp:
	$(CC) $(flags) *.cpp

clean: 
	rm -rfv ./build

install:
	cp -vi ./build/bin/hello /usr/bin/hello

uninstall:
	rm -vi /usr/bin/hello
