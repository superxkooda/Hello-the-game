#ifndef TITLESCREEN_h
#define TITLESCREEN_h
class titleScreen 
{

   public:
    titleScreen(struct title a);
    ~titleScreen();
    void start();

//		bool gameOver(void);

};

struct title
{
   std::string * ascii;
   char * h;
   char * e;
   char * l;
   char * l2;
   char * o;
};



#endif

