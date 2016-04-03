#include "common.h"
#include "myLib.h"
#include "titleScreen.h"
#include <string>
#include "tree.h"


int main()
{
//if windows i want to set the cmd terminal to an appropriate size
#ifdef _WIN32
    system("mode 800");
	SetConsoleTitle("Hello The Game");
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd,SW_SHOWMAXIMIZED);
#endif
   
    ncursesInit();
    getStdScr();
    if(stdy<40|| stdx<80)
    {
        clear();
        endwin();
        std::cout<<std::endl<<"Your framebuffer/terminal window is to small.\n Please enlarge the window or change your frame buffer settings and reboot. Then re-launch Hello the Game and enjoy :).\n"<<
            "Your current framebuffer only supports "<<stdx<<" by "<<stdy<<" and must be able to support at least 80 by 40 characters .";
        return 1;

    }
    //write my code below this line the above must stay
//------------------------------------------------------------------------------------------------------------------------------------------

    //some day this will be in a plane text file. now is not the time. soon ... soon 
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


    // ----23--- char each
    char h[] = "10001010h10101 101     ";//8
    char e[] = "   010FA101e0101010    ";//11
    char l[] = "1E00  1010101l01010111 ";//13
    char l2[] ="10101010101010l1 10  1 ";//14
    char o[] = "     010101010001o011t ";//17

    struct title content;
    content.ascii=ascii;
    content.h = h;
    content.e = e;
    content.l = l;
    content.l2 = l2;
    content.o = o;

    titleScreen HelloTheGame(content);
    classicMode();
    quit();

    return 0;
}


