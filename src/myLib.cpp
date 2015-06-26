#define MYLIB_H
#include "common.h"
#include <time.h>
//declarations
double TIMER =1;//for my SLEEP timer;
WINDOW * win;
int stdx, stdy;
void ncursesInit();
void wrapper();
void getStdScr();
void classicMode();
void bclear(WINDOW * window);
void quit();
void TBA(std::string feature);


class menu
{
    std::string * elements;
    int spacing;
    bool vertical;
public:
    int size;
    menu(bool isVertical, int space, int tmpSize, std::string * inElements);
    ~menu();
    void draw(WINDOW * winn, int selected, int x, int y);
};


class timer {
	private:
		double begTime;
	public:
		void start();
		double elapsedTime();
		bool isTimeout(double seconds);
};
//definitions

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
    std::exit(0);
}
//catch features that i have not added yet
void TBA(std::string feature)
{
    clear();
    printw("This feature \"%s\" has not been implemented yet and is in the works :)\n These new and exciting features are just on the horizon. \n press any key to quit\n",feature.c_str());
    timeout(-1);
    getch();
}



menu::menu(bool isVertical, int space, int tmpSize, std::string inElements[])
{
    std::cout<<length(inElements);
    size=tmpSize;
    vertical=isVertical;
    spacing=space;
    elements = new std::string[size];
    for(int i=0; i<size; i++)
        elements[i]=inElements[i];
}
menu::~menu()
{
    delete elements;
}

void menu::draw(WINDOW * winn, int selected, int x, int y)
{
    int xspacing=0;
    int yspacing=0;
                 for(int i=0; i<4; i++)
    {
        if(i!=0)
        {
            if(vertical==true)
                yspacing=yspacing+spacing+1;//no matter what for vertical you need to go down by one
            else
                xspacing=xspacing+elements[i-1].size() +spacing;
        }
        else
            xspacing=yspacing=0;

        if(i==selected)
            wattron(win,COLOR_PAIR(1));//

        mvwprintw(winn, (y+yspacing),(x+xspacing) , "%s", elements[i].c_str());

        if(i==selected)
            wattroff(win,COLOR_PAIR(1));
    }
}
//timer class
		void timer::start() {
			begTime = clock();
		}

		double timer::elapsedTime() {
			return ((double) clock() - begTime) / CLOCKS_PER_SEC;
		}

		bool timer::isTimeout(double seconds) {
			return seconds >= elapsedTime();
		}

    void SLEEP(double time)
    {
        timer T;
        T.start();
         while(true)
        {
            if(T.elapsedTime() >= time)
			break;

        }
    }
    void SLEEP()//default to 60 times a second
    {
        SLEEP(.01666);
    }
