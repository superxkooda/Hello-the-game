#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include "stats.h"
int main()
{
   tracker test;
  cout<<test.read("question",0)<<endl;
    //cout<<test.read("question",3)<<endl;
    cout<<test.where()<<endl;



    return 0;
}


