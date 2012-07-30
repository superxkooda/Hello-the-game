#ifndef MENU_H
#define MENU_H
#include "common.h"
class menu
{
    struct _score;
    struct _score  * score;

    int x, y, iterations, time;
    void title(int maxX, int maxY);
    void titleSplash();
    void fall(bool, int&, int, int);
    void init(void);
    int Qtype(string question);

    int questWrapper(_score *score);

int quest(int where, WINDOW * win);


    WINDOW * win;
public:
    menu();
    void start(void);

//		bool gameOver(void);

};



#endif

