#ifndef MENU_H
#define MENU_H
class titleScreen 
{

    int x, y, iterations, time;
    void animate(int maxX, int maxY);
    void splash();
    //  void fall(bool, int&, int, int);
    void fall(int startX, int startY, int speed);
    void title();


public:
    titleScreen();
    ~titleScreen();
    void start();

//		bool gameOver(void);

};



#endif

