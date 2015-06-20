#ifndef MENU_H
#define MENU_H
class gameObj
{

    int x, y, iterations, time;
    void title(int maxX, int maxY);
    void titleSplash();
    //  void fall(bool, int&, int, int);
    void fall(int startX, int startY, int speed);
    void titleScreen();
    int score;
    void gameOver(int how);
    void mainMenu();


public:
    gameObj();
    ~gameObj();
    void handler();

//		bool gameOver(void);

};



#endif

