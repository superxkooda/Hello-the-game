#ifndef MENU_H
#define MENU_H
#include "common.h"
class menu
{

    int x, y, iterations, time;
    void title(int maxX, int maxY);
    void titleSplash();
    void fall(bool, int&, int, int);

public:
    menu();
    void init();
    int score;
    void gameOver(int how);
    void mainMenu();

//		bool gameOver(void);

};



#endif

