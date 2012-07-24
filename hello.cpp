#include "hello.h"

void ncursesInit()
{
	initscr();
	keypad(stdscr, true);
	if(has_colors() == FALSE)
	{endwin();
		printw("Your terminal does not support color\n");
	}
	else
		use_default_colors();



	//	noecho();
	//raw();
}


void q1()
{
    cbreak();
    echo();
    keypad(stdscr, TRUE);
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
			printw("You have enterd an unacceptable answer. \n Go fuck yourself! and have a nice day \n");
		refresh();
		printw( "Play agoin? (y/n)?\n :");
		refresh();
		getstr(exit);
		while (exit[0]!='y' && exit[0]!='n')
		{
			printw("WRONG! y to play again n to exit! \n :");
			refresh();
			getstr(exit);
		}
	}
}
