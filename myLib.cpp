
#include "myLib.h"

void ncursesInit()
{
	initscr();
	keypad(stdscr, true);
	if(has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
	}
	else
		use_default_colors();



	noecho();
	//raw();
}

void wrapper()
{


	win = newwin(40,80,((stdy/2)-20),((stdx/2)-40));
	box(win,0,0);
	refresh();
	wrefresh(win);

}

void getStdScr()
{
	getmaxyx(stdscr, stdy, stdx);
}

void newGame()
{
	score=0;
}

void bclear(WINDOW * window)
{
	wclear(window);
	box(win,0,0);
	wrefresh(window);
}

void quit()
{
	clear();
	move(0,0);
	refresh();
	endwin();
	std::exit(0);
}
void TBA(std::string feature)
{
    clear();
    printw("This feature \"%s\" has not been implemented yet and is in the works :)\n These new and exciting features are just on the horizon. \n press any key to quit\n",feature.c_str());
    timeout(-1);
    getch();
    quit();
}
