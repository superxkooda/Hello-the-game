#define MYLIB_H
#include "common.h"
#include <time.h>
//declarations
double TIMER =1;//for my SLEEP timer;
WINDOW * win;
int stdx, stdy;

void ncursesColorInit()
{
	use_default_colors();
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_GREEN, -1);
	init_pair(3, COLOR_YELLOW, -1);
	init_pair(4, COLOR_BLUE, -1);
	init_pair(5, COLOR_MAGENTA, -1);
	init_pair(6, COLOR_CYAN, -1);
	init_pair(7, COLOR_WHITE, -1);
}

void ncursesInit()
{
    initscr();
    keypad(stdscr, true);
    if(has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
		exit(1);
    }
	start_color();
	ncursesColorInit();
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

void classicMode()
{
    cbreak();
    echo();
    keypad(stdscr, true);
    refresh();
	char exit[1];
	exit[0] = 'y';
	char day[1];
	while(exit[0] != 'n' )
	{
		clear();
		printw("Hello how is your day going \n Answers: 1 = good, 2 = bad \n : ");
		getstr(day);
		clear();
		refresh();
		if (day[0] == '1')
			printw("Thats good you keep having a good day. \n Don't let me get in the way of that.\n");

		else if (day[0] == '2')
			printw("Im sorry to hear that. ... \n you know there is traffic on the street outside.\n");

		else
			printw("You have enterd an unacceptable answer. \n You should be ashamed of yourself! Think about the traffic outside and have a nice day \n");
		refresh();
		printw( "Play again? (y/n)?\n : ");
		refresh();
		getstr(exit);
		if(exit[0]!='y' && exit[0]!='n') {
		while (exit[0]!='y' && exit[0]!='n')
		{
			printw("WRONG! y to play again n to exit! \n :");
			refresh();
			getstr(exit);
		}
		}
	}
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
   // refresh();
    endwin();
}
void softQuit()
{
    move(0,0);
   // refresh();
    endwin();
}
//catch features that i have not added yet
void TBA(char * feature)
{
    clear();
    printw("This feature \"%s\" has not been implemented yet and is in the works :)\n These new and exciting features are just on the horizon. \n press any key to quit\n",feature);
    timeout(-1);
    getch();
}

