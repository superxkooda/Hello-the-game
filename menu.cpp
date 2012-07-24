#include "menu.h"

int menu::init()
{
	curs_set(0);
	raw();
	noecho();
	keypad(stdscr, TRUE);
	int wait = -1;

	while( wait == -1 )
	{
		animate(stdx, stdy);
		timeout(16.667);
		wait = getch();
		refresh();
	}
	timeout(-1);
	curs_set(1);
	return 0;
}

void menu::animate(int maxX, int maxY)
{
	static int x , y , t, i; //positions
	static bool test[3] = { false };//has ran
	//	static char hello[1][5];
	x=(maxX/2)-2;
//first time running program ... initiallizer
	if(test[0] != true)
	{

		i=0;
		test[0] = true;
		y=0;
	}
//start the clock if not done so already
	if(test[1] !=true)
	{
		t=0;
		test[1] = true;

	}

	if ( t == CLOCK)//clock
	{

		t=0;
		if (i<23)
			fall(false, i , x, y);
		else if(i<47)
			fall(true, i ,x , y);
		else
		{
			test[2] =true;
			i=0;
		}
		if (test[2] == true)
			title();

	}

	else
		t++;
}

void menu::title()
{
    int y=25;
string ascii[9];
ascii[0]=" ___________  __    __    _______       _______       __       ___      ___   _______ ";

ascii[1]="(\"     _   \")/\" |  | \"\\  /\"     \"|     /\" _   \"|     /\"\"\\     |\"  \\    /\"  | /\"     \"|";

ascii[2]=" )__/  \\\\__/(:  (__)  :)(: ______)    (: ( \\___)    /    \\     \\   \\  //   |(: ______)";

ascii[3]="    \\\\_ /    \\/      \\/  \\/    |       \\/ \\        /' /\\  \\    /\\\\  \\/.    | \\/    |  ";

ascii[4]="    |.  |    //  __  \\\\  // ___)_      //  \\ ___  //  __'  \\  |: \\.        | // ___)_ ";

ascii[5]="    \\:  |   (:  (  )  :)(:      \"|    (:   _(  _|/   /  \\\\  \\ |.  \\    /:  |(:      \"|";

ascii[6]="     \\__|    \\__|  |__/  \\_______)     \\_______)(___/    \\___)|___|\\__/|___| \\_______)";

ascii[7]=" _____________________________________________________________________________________" ;

ascii[8]="                           ---Press any key to continue---";

for(int loop =0; loop<9;loop++)
{
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
					start_color();
					init_pair(1, COLOR_GREEN, COLOR_BLACK);
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


