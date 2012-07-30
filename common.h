#ifndef COMMON_H
	#define COMMON_H
       //things that all files need
			#include <curses.h>
			#include <string.h>
			#include <cstring>
			#include <iostream> //for debugging
            //#include "myLib.h"


			using namespace std;
			#ifdef _WIN32//are we running windows?

			#define CLOCK 2
			#include "WIN32.h"
			#endif

			#ifndef _WIN32

			#define CLOCK 8


			#endif

			#define TIMER 16.667

		#ifndef MAIN_H
			#ifndef NON_MAIN_COMMON
			#define NON_MAIN_COMMON

			//common things that i dont want to put in each header file
			extern void getStdScr();
			extern int stdx, stdy;
		#endif
	#endif

	//my common library
//	void animate(COORD &start, COORD &slope, char obj[], WINDOW *win);
#endif
