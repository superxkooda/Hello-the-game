
#ifndef TRACKER_H
#define TRACKER_H
#include <fstream>
#include <iostream>
#include "tree.h"
#include <string>
#include "StackLL.h"
class tracker
{
    struct obj
    {
        std::string name;
        std::string description;

         obj * children;
         obj * parent;
    };
    std::string getTag(std::ifstream& data);
    std::string grabContent(std::ifstream& data);
    bool load(std::string file);
    tree<std::string> * level;
   // int index(std::string tmp);// tell what indexed value a sertain tag has.
    std::string revIndex(int x);//if given an index value it returns the string
    int loc[2];
    bool mode;
    Stack<std::string> questions;
    //std::string *qIndex; //an array that will hold a index of all of our questions
    void populateIndex();//populate the array witht the contents of the indexed questions
    int qs;

public:
    std::string *qIndex;
    tracker();
    ~tracker();
    //tracker(std::string saveFile);
    int score;
    std:: string read(std:: string tag, int index);// move to the appropreate question or answer then returns the content of the tag
    std::string read();//returns the current item's content
    std::string where();// tell the current location in refrence to question and depth \\currently useless.
    std:: string type();// returns the content type
    std:: string answer(std::string ans);// imput the answer if it is a text based answer and retrive the response
    std:: string answer(int index);// if the answer is a menue based answer this is what you use
    bool saveGame();
    void toRoot();//return to root at any time
    void test();
};
#endif
