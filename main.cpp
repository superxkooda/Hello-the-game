#include "main.h"
int main()
{
	ncursesInit();
	getStdScr();

	sup.init();
		 q1();
 refresh();
 getch();
	endwin();
	return 0;
}

void getStdScr()
{
getmaxyx(stdscr, stdy, stdx);
}
