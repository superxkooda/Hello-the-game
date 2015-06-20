#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H
#include<string>
template <class T>
class Stack
{
    template<class X>
    struct node
    {
        bool isSet;
        node(int x);
        X value;
        int index;
        node<X> * next;

    };

    node<T> * current;
    node<T> * head;
public:
    Stack();
    void push(T x);
    T pop();
    T peek();
    int size;
    int index();
};

#endif
