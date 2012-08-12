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
void bclear(WINDOW * window);
void quit();
void TBA(std::string feature);
#endif
