#include "menu.h"
/*
std::string QnA[]=
{
    //base question
    "Hello how is your day going? ",//0
    "ANS",
    "Good",
    "Bad",
    "EOQ",
    "this is the second question",//5
    "ANS",
    "this is the second answer",
    "SECOND ANSWER",
    "EOQ",
    "this is the third"

};
*/

std::string mainOptions[]=
{
    "New Game",
    "Continue",
    "High Score",
    "Exit"
};

menu::menu()
{

    x=0;
    y=0;
    iterations=0;
    time=0;


};

void menu::init()
{
    curs_set(0);
    raw();
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_GREEN, -1);
    int wait = -1;
    timeout(0);

    while( wait == -1 )
    {
        title(stdx, stdy);
        //MACRO
        wait = getch();
        refresh();
        SLEEP(TIMER);
    }
    timeout(-1);
    //keep hello at the top of the screen
    clear();
    attron(COLOR_PAIR(1));
    mvprintw(8,(stdx/2)-2,"hello");
    refresh();
    attroff(COLOR_PAIR(1));

    mainMenu();

}

void menu::title(int maxX, int maxY)
{
    x=(maxX/2)-2;

    if ( time == 8)//every 9 iterations animate
    {

        time=0;
        if (iterations<23)
            fall(false, iterations , x, y);
        else if(iterations<47)
            fall(true, iterations , x, y);
        else
        {
            iterations=0;
            titleSplash();
        }

    }

    else
        time++;
}

void menu::titleSplash()
{
    int y=25;
    std::string ascii[9];
    ascii[0]=" ___________  __    __    _______       _______       __       ___      ___   _______ ";



    ascii[1]="(\"     _   \")/\" |  | \"\\  /\"     \"|     /\" _   \"|     /\"\"\\     |\"  \\    /\"  | /\"     \"|";

    ascii[2]=" )__/  \\\\__/(:  (__)  :)(: ______)    (: ( \\___)    /    \\     \\   \\  //   |(: ______)";

    ascii[3]="    \\\\_ /    \\/      \\/  \\/    |       \\/ \\        /' /\\  \\    /\\\\  \\/.    | \\/    |  ";

    ascii[4]="    |.  |    //  __  \\\\  // ___)_      //  \\ ___  //  __'  \\  |: \\.        | // ___)_ ";

    ascii[5]="    \\:  |   (:  (  )  :)(:      \"|    (:   _(  _|/   /  \\\\  \\ |.  \\    /:  |(:      \"|";

    ascii[6]="     \\__|    \\__|  |__/  \\_______)     \\_______)(___/    \\___)|___|\\__/|___| \\_______)";

    ascii[7]=" _____________________________________________________________________________________" ;

    ascii[8]="                           ---Press any key to continue---";

    for(int loop =0; loop<9; loop++)
    {
        if(loop >4 && loop <7)
        {
            attron(COLOR_PAIR(1));
            mvprintw(y,(stdx/2)-43,"%s",ascii[loop].c_str());
            attroff(COLOR_PAIR(1));
        }
        else
            mvprintw(y,(stdx/2)-43,"%s",ascii[loop].c_str());
        y++;
    }

}

//this is the main menu animation
void menu::fall(bool over, int &i, int x, int y)
{
    //	----23--- char each
    //static char h[24] = {'1','0','0','0','1','0','1','0','h','1','0','1','0','1','0','1','0','1','0','1','1','1',' '};//8
    static char h[] = "10001010h10101 101     ";//8
    static char e[] = "   010FA101e0101010    ";//11
    static char l[] = "1E00  1010101l01010111 ";//13
    static char l2[] ="10101010101010l1 10  1 ";//14
    static char o[] = "     010101010001o011t ";//17
    //find out if this function has been called before
    int	z=i;
    int m=0;
    static int check=0;
    if(over==true)
    {
        m=m+(i-23);
        z=23;
        //if(z>m)
        //break;
    }
    while(z>-1)
    {
        if(m>=23)
            break;
        //print onto scren garbage from the arrays
        mvprintw(y+z,x,"%c",h[m]);
        mvprintw(y+z,x+1,"%c",e[m]);
        mvprintw(y+z,x+2,"%c",l[m]);
        mvprintw(y+z,x+3,"%c",l2[m]);
        mvprintw(y+z,x+4,"%c",o[m]);
        attron(COLOR_PAIR(1));
        switch(m)
        {
        case 8:
            mvprintw(y+z,x,"%c",h[m]);
            break;
        case 11:
            mvprintw(y+z,x+1,"%c",e[m]);
            break;
        case 13:
            mvprintw(y+z,x+2,"%c",l[m]);
            break;
        case 14:
            mvprintw(y+z,x+3,"%c",l2[m]);
            break;
        case 17:
            mvprintw(y+z,x+4,"%c",o[m]);
            break;
        }

        if((z+y==8 && m ==8) || check >=1)
        {
            mvprintw(8,x,"h");
            if(check<1)
            {
                h[m]=' ';
                check=1;
            }
        }
        if((z+y==8 && m ==11) || check >= 2)
        {
            mvprintw(8,x+1,"e");
            if(check<2)
            {
                check=2;
                e[m]=' ';

            }
        }
        if((z+y==8 && m ==13) || check >= 3)
        {
            mvprintw(8,x+2,"l");
            if(check<3)
            {
                l[m]=' ';
                check=3;

            }
        }
        if((z+y==8 && m ==14) || check >=4)
        {
            mvprintw(8,x+3,"l");
            if(check<4)
            {
                l2[m]=' ';
                check=4;

            }
        }
        if((z+y==8 && m ==17) || check == 5)
        {
            mvprintw(8,x+4,"o");
            if(check<5)
            {
                o[m]=' ';
                check=5;

            }
        }
        attroff(COLOR_PAIR(1));
        z--;
        m++;

    }
    i++;
}


//main menu
void menu::mainMenu()
{
    wrapper();
    int key;
    int selected=0;
    int exit=0;
//start our main loop for the menu
    while(exit==0)
    {
//draw our items and hilight the selected element
        for(int i=0; i<4; i++)
        {
            if(i==selected)
                wattron(win,COLOR_PAIR(1));//

            mvwprintw(win, (10+i),(35) , "%s", mainOptions[i].c_str());

            if(i==selected)
                wattroff(win,COLOR_PAIR(1));
        }

        wrefresh(win);
        timeout(0);
        key=getch();

        switch(key)
        {
        case KEY_UP:
            if(selected>0)
            {
                selected--;
            }
            break;

        case KEY_DOWN:
            if(selected<3)
            {
                selected++;
            }
            break;

        case KEY_ENTER:
        case 10:
        exit=1;
            break;

        default:
            break;


        }

        SLEEP(TIMER);
    }
    timeout(-1);

    switch(selected)
    {
    case 0: //"New Game":
    TBA("New Game");
    break;

    case 1: // "Continue":
    TBA("Continue");
    break;

    case 3: //"Exit":
    quit();
    break;
    }
}


/*int menu::questWrapper(_score * score)
{
    int total;
    win = newwin(40,80,((stdy/2)-20),((stdx/2)-40));
    box(win,0,0);
    refresh();

    wrefresh(win);

    quest(score->val, win);

    if(score->gameOver==0)
    {
        total=total+score->val;
        questWrapper(score);

    }
    else
    {
        score->val=total;
        return(score->gameOver);
    }
    return 0;
}

int menu::quest(int where, WINDOW * win)
{
    int test = 0;
    iterations=0;
    time=0;
    int keyDown=-1;
    timeout(TIMER);
    curs_set(1);
    while(keyDown==-1)
    {
        keyDown=getch();
        test=Qtype(QnA[Qindex[where]]);
        wrefresh(win);
        time++;
        if(test==-1)
        break;
    }
    mvwprintw(win,3,5,"%s",QnA[Qindex[where]].c_str());
    wrefresh(win);
    timeout(-1);
    score->gameOver=1;
}

int menu::Qtype(string  question)
{
    //working index of the string
    if(time==CLOCK && iterations<question.size())
    {
     mvwprintw(win,3,(5+iterations),"%c",question[iterations]);
    iterations++;
    time=0;
        }
        else if(iterations==question.size())
        return -1;

}







*/
