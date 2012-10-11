#ifndef COMMON_H
#define COMMON_H
//things that all files need
#include <curses.h>
#include <string.h>
#include <cstring>
#include <cstdlib> //for debugging
#include <unistd.h>
#include <iostream>
#include "myLib.h"
#include "menu.h"


//using namespace std;

#ifdef _WIN32//are we running windows?
#define _WIN32_WINNT 0x0600
#include <windows.h>
#define SLEEP(a) Sleep(a)//in 1000s of a second

#endif

#ifndef _WIN32

#define SLEEP(a) usleep( a * 1000)//in 1 000 000s of a second// replaces CLOCK

#endif

#define TIMER 17 //for about 60 times a second rounding up form 16.666666
#define length(a) ( sizeof ( a ) / sizeof( a[0] ) )//get length of arrays may be handy



#endif
//EOCOMMON
