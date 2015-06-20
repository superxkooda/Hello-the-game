//textbook style link list
#include <string>
#include "StackLL.h"

template <class T>
template <class X>
Stack<T>::node<X>::node(int x)
{
    index =x;
}

template <class T>

 Stack<T>::Stack()
{
    head = new node<T>(1);
    head->next=0;
    head->isSet=false;
    current= head;
    size=0;
}

template <class T>
void Stack<T>::push(T x)
{

    if (current->isSet==false)
    {
        current->isSet=true;
        current->value=x;
        current->index=size;
        size++;
    }
    else
    {
        node<T> * temp;
        temp = new node<T>(current->index+1);
        temp->isSet= true;
        temp->next= current;
        current = temp;
        current->value=x;
        current->index=size;
        size++;

    }

}
template <class T>
T Stack<T>::pop()
{
    T tmpVal= current->value;
    if(current->next!=0)
    {
        node<T> * temp;
        temp = current;
        current = current->next;
        delete temp;
        size--;
    }
    else if(current->isSet==true)
    {
        size=0;
        current->isSet=false;
       // current->value=0;
    }
    return tmpVal;
}

template <class T>
T Stack<T>::peek()
{
    return current->value;

}

template <class T>
int Stack<T>::index()
{
return current->index;
}

template class Stack<std::string>;
template class Stack<int>;
template class Stack<double>;
