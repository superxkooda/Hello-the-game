#include "tree.h"
using namespace std;


template <class T>
template <class X>
tree<T>::node<X>::node(node<X> *p, string init)
{
    parent = p;
    type=init;
    children();
}
//first node's parent should be 0
template <class T>
template <class X>
tree<T>::node<X>::node(string init)
{
    parent =0;
    type=init;
    children();
}
//init all children to 0
template <class T>
template <class X>
void tree<T>::node<X>::children()
{
    left=0;
    right=0;
}

template <class T>
template <class X>
tree<T>::node<X>::~node()
{
    delete left;
    delete right;
}

template <class T>
tree<T>::tree(T content)
{
    head = new node<T>("root");
    head->value = content;
    index= new node<T>("root");
    index->left=head;
    index->right=index;
    current= head;
    right=true;

}
template<class T>
tree<T>::~tree()
{
    delete head;
}

template <class T>
int tree<T>::push( T content, string type )
{
int wasIndexed;
//temp variable to keep track if the type was inexed.
    if(!full)
    {
        //check if it is indexed and if it is move to the first item in the index
        if(isIndex(type))
            {
                moveTo(type);
                wasIndexed=1;
            }//this will place it with like items in the tree for oginization sake
            //if it is a non indexed item it simply starts from the current position and goes left or right accordingly
            else wasIndexed=0;

        //only change directions when type changes;
        if(type!=current->type)
            right= !right;
        if(right)
            newNode(current->right,  content, type);
        else
            newNode(current->left,  content, type);
            return wasIndexed;
    }
    else
    return -1;//if full obviously

}
/*
this version of push is to support the indexing function.
if it is not already indexed then it will be indexed at
the current location and all other subsiquent items of the
same type will be placed in sucsession.
*/
template <class T>
int tree<T>::push( T content, string type, bool indexed )
{
    if(!full)
    {

        if(push(content, type)==0)//make sure the content has been pushed and was not indexed before indexing it.
        {
        node<T> * tmp = new node<T>(type);
        tmp->left= current;
        tmp->right=index->right;
        index->right=tmp;
        return 0;
        }
        else
        return 1;
    }
    return -1;

}

template<class T>
void tree<T>::newNode(node<T> * N, T content, string type)
{

    if(N)
    {
        current=N;

         if(right)
            newNode(current->right,  content, type);
        else
            newNode(current->left,  content, type);
    }
    else
    {


        N =new node<T>(current, type);
        N->value= content;


        if(right)
            current->right=N;
        else
            current->left=N;

        current=N;

    }
}


template<class T>
bool tree<T>::moveTo(T content, string type)
{
    if(moveTo(type))
    {
                return search(content);
    }
    else
        return false;
}

template<class T>
bool tree<T>::moveTo(string type)
{
    string stopper;// this is to prevent an infinant loop when this gets called and the item is not indexed
    node<T> * tmp;
    tmp= index;
    stopper = tmp->type;//what i said above
    while(tmp->type!=type)
    {
        tmp=tmp->right;
        if(tmp->type==stopper)
            break;
    }
    if(tmp->type!=stopper||type=="root")//||tmp->type==type)
    {
        current=tmp->left;


        if(current->parent)
        {
            node<T> * parent;
            parent = current->parent;

            if(parent->right!=0&&parent->right->type==type)//this will check from the parent (which should be of a diffrent type)
                right=true;//if the nodes of this type go left or right;
            else
                right=false;
        }
        return true;
    }
    else
        return false;

}

template<class T>
bool tree<T>::isIndex(string type)
{
    string stopper;// this is to prevent an infinant loop when this gets called and the item is not indexed
    node<T> * tmp;
    tmp= index;

    stopper = tmp->type;//what i said above
    while(tmp->type!=type)
    {
        tmp=tmp->right;
        if(tmp->type==stopper)
            break;
    }
    if(tmp->type!=stopper||type=="root")//||tmp->type==type)
        return true;
    else
        return false;


}

template<class T>
bool tree<T>::search(T content)
{
    int x=0; //need to keep track of how far into the list we go so if it is not there we can back up.
    //unfortunatly i cant use a tmp node because of my dependancy on my next function and only
    //switch the current if we find a match this is like this becuse im lazy.
    do
    {
        x++;

        if(current->value==content)
            return true;
    }
    while(next());
    for(int i=x; i>0; i--)
    {
        current=current->parent;
    }
    return false;

}
template<class T>
bool tree<T>::next()
{

    if(right&&current)
    {
        if(current->right!=0)
        {
            current=current->right;
            return true;
        }
        else return false;
    }
    else if(!right)
    {
        if(current->left!=0)
        {
            current=current->left;
            return true;
        }
        else return false;
    }
    else return false;

}

template<class T>
bool tree<T>::up() //used to go up one node
{
    if(current->parent!=0)
    {
        current=current->parent;
        return true;
    }
    else return false;

}

template<class T>
void tree<T>::done()
{
    full=true;
}

template<class T>
void tree<T>::turn()
{
    right=!right;
}

template<class T>
string * tree<T>::peek()
{
   string * tmp = new string[2];
   tmp[0]=current->type;
   tmp[1]=current->value;
   return tmp;


}

template class tree<string>;

