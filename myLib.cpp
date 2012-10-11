#define MYLIB_H
#include "common.h"
//declarations
WINDOW * win;
int stdx, stdy;
void ncursesInit();
void wrapper();
void getStdScr();
void newGame();
void bclear(WINDOW * window);
void quit();
void TBA(std::string feature);

struct stats
{
    int score;
    std::string level;
    int track;
    stats();
    stats(std::string loadLevel, int loadScore, int loadTrack);

};
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
stats * tracker;
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

    noecho();
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
    tracker= new stats;
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
    delete tracker;
    std::exit(0);
}
//catch features that i have not added yet
void TBA(std::string feature)
{
    clear();
    printw("This feature \"%s\" has not been implemented yet and is in the works :)\n These new and exciting features are just on the horizon. \n press any key to quit\n",feature.c_str());
    timeout(-1);
    getch();
    quit();
}


//stats struct
stats::stats()
{
    score=track=0;
    level="new";

}

stats::stats(std::string loadLevel, int loadScore, int loadTrack)
{
    score=loadScore;
    level=loadLevel;
    track=loadTrack;
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
