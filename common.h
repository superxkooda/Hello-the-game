#ifndef COMMON_H
	#define COMMON_H
       //things that all files need
			#include <curses.h>
			#include <string>
			using namespace std;
			#ifdef _WIN32
			#define CLOCK 2
			#endif
			#ifndef _WIN32
			#define CLOCK 8
			#endif

		#ifndef MAIN_H
			#ifndef NON_MAIN_COMMON
			#define NON_MAIN_COMMON
			//common things that i dont want to put in each header file
			extern void getStdScr(string);
			extern int stdx, stdy;
		#endif
	#endif
#endif
