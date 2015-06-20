#include "common.h"
using namespace std;
int main()
{
#ifdef _WIN32
    system("mode 120,60");
#endif


    ncursesInit();
    getStdScr();
    if(stdy<40|| stdx<80)
    {
        clear();
        endwin();
        cout<<endl<<"Your framebuffer/terminal window is to small.\n Please enlarge the window or change your frame buffer settings and reboot. Then re-launch Hello the Game and enjoy :).\n"<<
            "Your current framebuffer only supports "<<stdx<<" by "<<stdy<<" and must be able to support at least 80 by 40 characters .";
        return 1;

    }

    gameObj HelloTheGame;
    HelloTheGame.handler();


    endwin();



    return 0;
}

