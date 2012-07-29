#ifndef MENU_H
#define MENU_H
#include "common.h"
class menu{
   int x, y, iterations, time;
	void title(int maxX, int maxY);
	void titleSplash();
	void fall(bool, int&, int, int);
	void init(void);
	int questionWrapper(void);

	WINDOW * win;
	public:
	menu();
	void start(void);

//		bool gameOver(void);

};

#endif

