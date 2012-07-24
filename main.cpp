#include "main.h"
int main()
{
	ncursesInit();
	getStdScr();

	hello.init();
		q1();

 refresh();


	endwin();
	return 0;
}

void getStdScr()
{
getmaxyx(stdscr, stdy, stdx);
}
