#first makefile
CC = c++
flags=-c -Wall
all: convo

convo: main.o hello.o
	$(CC) *.o -o ./build/bin/hello -lcurses 
	mv -v *.o ./build

main.o: main.cpp
	$(CC) $(flags) main.cpp

hello.o:
	$(CC) $(flags) hello.cpp 

clean: 
	rm -rfv ./build/{*.o,bin/hello}

install:
	cp -vi ./build/bin/hello /usr/bin/hello

uninstall:
	rm -vi /usr/bin/hello
