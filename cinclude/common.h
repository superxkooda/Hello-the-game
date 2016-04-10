#ifndef BASE_H
#define BASE_H
#include<stdio.h>
#include <curses.h>
#include <stdlib.h>
typedef struct _COORD {
	int x;
	int y;
	} cCoord;

#ifdef _WIN32//are we running windows?
#define _WIN32_WINNT 0x0600
#include <windows.h>
#endif

#define MAX_LINES 200

#endif
