#ifndef MYLIB_H
#define MYLIB_H

extern WINDOW * win;
extern int stdx, stdy;
void ncursesInit();
void wrapper();
void getStdScr();

void newGame();
void bclear(WINDOW * window);
void quit();
void TBA(std::string feature);

struct stats
{
    int score;
    std::string level;
    int track;
    stats();
    //work to do add load state initializer
    //stats(std::string loadLevel, int loadScore, int loadTrack);

};
class menu
{
    std::string * elements;
    int spacing;
    bool vertical;
public:
    int size;
    menu(bool isVertical, int space, int tmpSize, std::string * inElements);
    ~menu();
    void draw(WINDOW * winn, int selected, int x, int y);
};
extern stats * tracker;
#endif
