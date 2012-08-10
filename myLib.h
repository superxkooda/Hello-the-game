#ifndef MYLIB_H
#define MYLIB_H
#include "common.h"
#include "menu.h"
WINDOW * win;
void ncursesInit();
void wrapper();
void getStdScr();
int stdx, stdy;
int score;
void newGame();
std::string keyPress();
void bclear(WINDOW * window);
void quit();
#endif
