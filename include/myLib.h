#ifndef MYLIB_H
#define MYLIB_H
extern double TIMER;//for my SLEEP timer;
extern WINDOW * win;
extern int stdx, stdy;
void ncursesInit();
void wrapper();
void getStdScr();

void classicMode();
void bclear(WINDOW * window);
void quit();
void TBA(std::string feature);


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

class timer {
	private:
		double begTime;
	public:
		void start();
		double elapsedTime();
		bool isTimeout(double seconds);
};

void SLEEP(double time);
void SLEEP();

#endif
