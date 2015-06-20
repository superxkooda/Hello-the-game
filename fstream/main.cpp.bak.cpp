#include <iostream>
#include <fstream>
#include <string>
#include "StackLL.h"


using namespace std;

int main()
{

    Stack<string> type;
    Stack<string>  content;

    try
    {
        ifstream data;
        data.open("test.txt",ios::in);
        string temp;
        string yo="done";
        char tmp[2];
        while(temp!="done")
        {
        temp=tmp[0]=tmp[1]=NULL;



//make sure to skip over return charicters
            do
            {
                tmp[0]=data.get();
                tmp[1]=data.peek();

            }
            while(tmp[0]=='\n');

            //find the begining of a tag
            if(tmp[0]=='<'&&tmp[1]!='/')
            {

                //grab the tag name
                while(tmp[0]!='>')
                {
                    tmp[0]=data.get();
                    temp= temp+tmp[0];
                    tmp[0]=data.peek();
                }
                cout<<temp<<endl;
                if(temp!="done")
                      temp=tmp[0]=tmp[1]=NULL;

                if(temp==yo)
                cout<<"i should be closing now";


                //push the tag name to store the type
               /* if(temp!="done")
                {

                    type.push(temp);
                    //reset value
                    temp=tmp[0]=tmp[1]=NULL;
                    do
                    {
                        tmp[0]=data.get();
                        tmp[1]=data.peek();

                    }
                    while(tmp[0]=='\n');
                    //now lets grab the contents of the tag and stop where we find the next tag


                    while(tmp[0]!='<')
                    {
                        tmp[0]=data.get();
                        temp= temp+tmp[0];
                        tmp[0]=data.peek();
                    }
                    content.push(temp);
                    //data.ignore();

                }
                else break;
*/
                //cout<<"\n\tcontent type = "<< type.peek()<<"\n\tcontent: "<<content.peek()<<"\n";

            }//skip over close tags need to work on this step but for now we ignore them
            else if(tmp[1]=='/')
            {


                while(tmp[0]!='>')
                {
                    data.ignore();
                    tmp[0]=data.peek();
                }
            }
            else
                data.ignore();



        }



        data.close();


    }
    catch(exception X)
    {
        cout<<"\n\t cannot load file";
    }
    return 0;
}
