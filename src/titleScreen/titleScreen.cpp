#define TITLESCREEN_h
#include "common.h"
#include "myLib.h"
struct title
{
   std::string * ascii;
   char * h;
   char * e;
   char * l;
   char * l2;
   char * o;
};

class titleScreen
{

    int x, y, iterations, time;
    void animate(int maxX, int maxY);
    void splash();
    void fall(int startX, int startY, int speed);
    void showTitle();
    title * content;

public:
    titleScreen(struct title content);
    ~titleScreen();
    void start();
};



titleScreen::titleScreen(struct title a)
{

    x=0;
    y=0;
    iterations=0;
    time=0;
    start_color();
    init_pair(1, COLOR_GREEN, -1);
    init_pair(2,COLOR_BLACK,COLOR_GREEN);
    content=&a;
    start();


};

titleScreen::~titleScreen()
{
    delete content;
}

void titleScreen::start()
{

    //lets start the game
    showTitle();

}

void titleScreen::showTitle()
{
    curs_set(0);
    raw();
    noecho();
    keypad(stdscr, TRUE);

    int wait = -1;
    timeout(0);

    while( wait == -1 )
    {

        animate(stdx, stdy);
        //MACRO
        wait = getch();
        refresh();
        SLEEP();//this is my implementation of sleep on a timer

        }

    timeout(-1);
    //keep hello at the top of the screen
    clear();
    attron(COLOR_PAIR(1));
    mvprintw(8,(stdx/2)-2,"hello");
    refresh();
    attroff(COLOR_PAIR(1));

}


void titleScreen::splash()
{
    int y=25;
    for(int loop =0; loop<9; loop++)
    {
        if(loop >4 && loop <7)
        {
            attron(COLOR_PAIR(1));
            mvprintw(y,(stdx/2)-43,"%s",content->ascii[loop].c_str());
            attroff(COLOR_PAIR(1));
        }
        else
            mvprintw(y,(stdx/2)-43,"%s",content->ascii[loop].c_str());
        y++;
    }

}

//this is the main menu animation
void titleScreen::fall(int startX, int startY, int speed)
{

   

    static int ticks;//clock ticks aka speed of animation
    static int i=0;//iterator
    int	z=i;
    int m=0;
    static int check=0;
    if(ticks==speed)
    {
        ticks=0;

        if(i>23)
        {
            m=m+(i-23);
            z=23;
            if(i>47)
            {
                i=0;
                splash();
            }
        }
        while(z>-1)
        {
            if(m>=23)
                break;
            //print onto scren garbage from the arrays
            mvprintw(startY+z,x,"%c",content->h[m]);
            mvprintw(startY+z,x+1,"%c",content->e[m]);
            mvprintw(startY+z,x+2,"%c",content->l[m]);
            mvprintw(startY+z,x+3,"%c",content->l2[m]);
            mvprintw(startY+z,x+4,"%c",content->o[m]);

            //did we hit a letter in hello?
            attron(COLOR_PAIR(1));
            switch(m)
            {
            case 8:
                mvprintw(startY+z,startX,"%c",content->h[m]);
                break;
            case 11:
                mvprintw(startY+z,startX+1,"%c",content->e[m]);
                break;
            case 13:
                mvprintw(startY+z,startX+2,"%c",content->l[m]);
                break;
            case 14:
                mvprintw(startY+z,startX+3,"%c",content->l2[m]);
                break;
            case 17:
                mvprintw(startY+z,startX+4,"%c",content->o[m]);
                break;
            }

            if((z+startY==8 && m ==8) || check >=1)
            {
                mvprintw(8,startX,"h");
                if(check<1)
                {
                    content->h[m]=' ';
                    check=1;
                }
            }
            if((z+startY==8 && m ==11) || check >= 2)
            {
                mvprintw(8,startX+1,"e");
                if(check<2)
                {
                    check=2;
                    content->e[m]=' ';

                }
            }
            if((z+startY==8 && m ==13) || check >= 3)
            {
                mvprintw(8,startX+2,"l");
                if(check<3)
                {
                    content->l[m]=' ';
                    check=3;

                }
            }
            if((z+startY==8 && m ==14) || check >=4)
            {
                mvprintw(8,startX+3,"l");
                if(check<4)
                {
                    content->l2[m]=' ';
                    check=4;

                }
            }
            if((z+startY==8 && m ==17) || check == 5)
            {
                mvprintw(8,startX+4,"o");
                if(check<5)
                {
                    content->o[m]=' ';
                    check=5;

                }
            }
            attroff(COLOR_PAIR(1));
            z--;
            m++;

        }
        i++;
    }
    else
        ticks++;


}

void titleScreen::animate(int maxX, int maxY)
{
    y=x=0;
    x=(maxX/2)-2;
    fall(x,y,5);
}

