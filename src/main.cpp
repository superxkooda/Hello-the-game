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

    titleScreen HelloTheGame(ascii);
    quit();

    return 0;
}


