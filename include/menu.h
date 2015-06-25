#ifndef MENU_H
#define MENU_H
class titleScreen 
{

    int x, y, iterations, time;
    void animate(int maxX, int maxY);
    void splash();
    void fall(int startX, int startY, int speed);
    void title();
    std::string * ascii;


public:
    titleScreen(std::string * txt);
    ~titleScreen();
    void start();

//		bool gameOver(void);

};



#endif

