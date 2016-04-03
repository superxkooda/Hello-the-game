#ifndef QUEUE_H
#define QUEUE_H
#include <string>

template <class T>
class tree
{
    template <class X>
    struct node
    {
        std::string type;
        X value;
        node(node<X> * p, std::string init);
        node(std::string init);
        ~node();
        node * left;
        node * right;
        node * parent;
private:
        void children();
    };

    node<T> * current;
    node<T> * head;
    node<T> * index;//indexing linked list for our tree type is the type of the data indexed.
    //this will always point to the first item in a list of a given type
    //left is a pointer to the data and right points to the next item in the list this is for faster searching.
    bool right, full;//if right is true we go right. if full is true you can no loger push values.
    void newNode(node<T> * N, T content, std::string type);//this is so i dont need to re-write the same add every time

public:

    tree(T content);
    ~tree();

    bool isIndex(std::string type);
    bool next();//moves one node down from current position in direction of "right"
    bool moveTo(T content, std::string type);//moves to the location of a member of  specified type and contaning the content you are looking for
    bool moveTo(std::string type);//moves to the first element of type "type" that has been indexed.
    bool up();
    bool search(T content);//looks for a node with spcified content within the current type
    void turn();//if bool right=true it now = false
    int push(T content, std::string type);
    int push( T content, std::string type, bool indexed );//for indexing obviously;
    std::string * peek();//for now its one function to retun an array of type and content;
    void done();


};






#endif // QUEUE_H
