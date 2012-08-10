#ifndef COMMON_H
	#define COMMON_H
       //things that all files need
			#include <curses.h>
			#include <string.h>
			#include <cstring>
			#include <cstdlib> //for debugging
			#include <unistd.h>
			#include <iostream>
			#include "menu.h"


			//using namespace std;

			#ifdef _WIN32//are we running windows?

            #define _WIN32_WINNT 0x0600
			#define CLOCK 2//only used for the opening animaitons repalaces clock
			#define SLEEP(a) sleep(a);//in 1000s of a second
			#include "WIN32.h"
			#endif

			#ifndef _WIN32

			#define CLOCK 8
			#define SLEEP(a) usleep( a * 1000);//in 1 000 000s of a second// replaces CLOCK

			#endif

			#define TIMER 17 //for about 60 times a second rounding up form 16.666666

		 #ifndef MAIN_H
			#ifndef NON_MAIN_COMMON
			#define NON_MAIN_COMMON

			//common things that i dont want to put in each header file




		#endif

	#endif
	//everything else if after here including everything common.cpp
//------------------------------------------------------------------------------------------

//anything in myLib MUST be externed to avoid multiple definitions error
    extern void getStdScr();
    extern int stdx, stdy, score;
    extern WINDOW * win;
    extern void ncursesInit();
    extern void wrapper();
    extern void newGame();
    extern std::string keyPress();
    extern void bclear(WINDOW * window);
    extern void quit();


#endif
//EOCOMMON
