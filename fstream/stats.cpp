#include "stats.h"
using namespace std;
tracker::tracker()
{
    //initializer for a new game
    std::string defaultFile="default.txt";
    if(load(defaultFile))
    populateIndex();

}
tracker::~tracker()
{
    delete level;
}

bool tracker::load(std::string file)
{

        ifstream data;


       data.open(file.c_str(),ios::in);
       if(data)
      {

        std::string tag, content;

        bool indexed[3],type;//type ==true: memu drven level
        /*
        this take note of what taggs that have been already indexed;
        0 - root
        1 - 1 type
        2 - question
        */
        for(int i =0; i<3; i++)indexed[i]=false;
        while(tag!="done")
        {
            //find the begining of a tag
            tag=getTag(data);


            //push the tag name to store the type

            if(tag!="done"&& tag!=""&&indexed[0]==true)
            {
                content="";//wipe content before preforming operation on it.

                content=grabContent(data);
                /*
                accepted tag types
                root - this is the first thing a user will see on any given level. think of it as the level title or description
                type - this will tell us if it is a menu driven level or if it will be context based. this is not stored in the tree
                question - this will be the text for the question. should be indexed!!
                answer - right leg of questions non indexed. depending on the type of question there will be a right leg called parts or reponses
                response - right or left leg of the answer limb it will be the end leaf
                score - this will be the respeced left or right leg of respone that should be checked for when a resonse is given. its igonred if null
                items - this is the list of items with an id number that are listed on the floor right leg from root.
                */

                if(tag=="type"&&indexed[1]==false)
                    //the first tag to be checked is the type tag and it must be there
                    //because without it I wont know how the user is supposed to interact.
                {
                    if(content=="menu")
                        type=true;
                    else if(content=="typed")
                        type=false;
                    if(type==true || type == false)//this will make sure the type tag's contents was not left blank
                        indexed[1]=true;
                }
                else if(tag=="typed")
                {

                    if(!indexed[2])
                    {
                        indexed[2]=true;
                    }

                    level->push(content, tag, true);
                    questions.push(content);
                    cout<<"pushing a question! "<<questions.peek()<<"\n the amount in questions is "<<questions.size<<endl;
                }
                else if(tag=="answer")
                {


                    level->push(content, tag);

                }
                else if(tag=="response")
                {


                    level->push(content, tag);
                }
                else if(tag=="score")
                {


                    level->push(content, tag);

                }
                else if(tag=="items")
                {


                    level->push(content, tag);
                    //level->push("false","" );

                }
                     else if(tag=="question")
                {


                    level->push(content, tag);
                    //level->push("false","" );

                }
                else
                {

                    cout<<"Illegal tag "<<tag<<endl;
                    tag="done";

                }

            }
            else  if(tag=="root")
            {
                indexed[0]=true;//bool value for root
                content=grabContent(data);
                //need to initialize our tree if it has not already
                level = new tree<std::string>(content);
            }
            else if(content==""&&tag!="done")
            {
                cout<<"empty tag in tag: "<<tag<<endl;
            }
            else continue;

        }






        data.close();//close our stream.
//once everything is read form the
// file it is time to move the tree back to its root.
        level->moveTo("root");//now that we are done loading lets move back to the first item in the tree
        loc[0]=loc[1]=0;//keeps track of where we are in relation to indexed questions



        return true;
    }
    else
    {
        cout<<"\n\t cannot load file";
        return false;
    }
}


std::string tracker::read()
{
    return level->peek()[1];
}

std::string tracker::read(std::string tag, int index)
{
    if(level->moveTo(qIndex[index], tag))
       return level->peek()[1];

    return "<!>error bad tag";

}

std::string tracker::grabContent(ifstream& data)
{
    std::string temp;
    char tmp;
    //this will remove all new line chars that are in the begining
    do
    {
        tmp=data.peek();
        if(tmp=='\n')
            data.ignore();

    }
    while(tmp=='\n');
    //now lets grab the contents of the tag and stop where we find the next tag


    while(tmp!='<')
    {
        tmp=data.peek();
        if(tmp=='\n')
            //if there is a new line replace it with a space formatting of text should be done entirely by the project
            tmp=' ';
        if(tmp!='<')
        {
            //i dont know why or works and && will not
            if(tmp!=' '|| temp!="")
                temp= temp+tmp;
            data.ignore();

        }
        else if(tmp=='<')
            break;
    }

    return temp;


}


std::string tracker::getTag(ifstream& data)
{
    //remove new line chars
    char tmp[2];
    std::string temp;
    while(1==1)
    {
        do
        {
            tmp[0]=data.get();
            tmp[1]=data.peek();

        }
        while(tmp[0]=='\n');

        if(tmp[0]=='<'&&tmp[1]!='/')
        {

            //grab the tag name
            while(tmp[0]!='>')
            {
                tmp[0]=data.get();
                if(tmp[0]!=' ')
                    temp= temp+tmp[0];

                tmp[0]=data.peek();
            }
            //return the found tag
            if(tmp[0]=='>')
                data.ignore();
            return temp;

        }//skip over close tags need to work on this step but for now we ignore them and return a null string
        else if(tmp[1]=='/')
        {


            while(tmp[0]!='>')
            {
                data.ignore();
                tmp[0]=data.peek();
            }
            return "";
        }
        else
            data.ignore();
    }


}

std::string tracker::where()
{
    return level->peek()[1];
}

void tracker::populateIndex()
{

int size = questions.size;
qs=size;
qIndex= new string[(size)];
for(int i=(size-1);i>-1;i-- )
  {
      qIndex[i]=questions.pop();
    }

  }

void tracker::test()
{

read();

    }








