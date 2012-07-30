#include "main.h"

int main()
{
    #ifdef _WIN32
   system("mode 120,60");
	#endif

	ncursesInit();
	getStdScr();
	if(stdy<60|| stdx<120)
	{
	    clear();
	    endwin();
	    cout<<endl<<"Your framebuffer/terminal window is to small.\n Please enlarge the window or change your frame buffer settings and reboot. Then re-launch Hello the Game and enjoy :).\n"<<
	    "Your current framebuffer only supports "<<stdy<<" by "<<stdx<<" and must be able to support at least 120 by 60 .";
	    return 1;

	}

HelloTheGame.start();
getch();

	endwin();


	return 0;
}

void getStdScr()
{
getmaxyx(stdscr, stdy, stdx);
}
