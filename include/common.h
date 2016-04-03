#ifndef BASE_H
#define BASE_H
//things that all files need
#include <curses.h>
#include <string.h>
#include <cstring>
#include <cstdlib> //for debugging
#include <unistd.h>
#include <iostream>


//using namespace std;

#ifdef _WIN32//are we running windows?
#define _WIN32_WINNT 0x0600
#include <windows.h>
#endif




#define length(a) ( sizeof ( a ) / sizeof( a[0] ) )//get length of arrays may be handy



#endif
//EOBASE
