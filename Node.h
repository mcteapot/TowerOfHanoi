
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

template<class T>
struct node //Linked List of type 'node' for tower of Hanoi
{
    T priority;//int data field for priority

    void nFresh();//initialez variables to defaults
    node();//constructor calls nFresh
    ~node();//destructor calls nFresh

    node(T arg);//single arguement constructor
    node(node *ptr);//copy constructor

    node& operator=(node *other);//assignment operator overload

    node *ptr; //tail
    //static int qCount;
};

template<class T>
void node<T>::nFresh()
{
    priority = 0;//negative 1 is a dummy negative value that implies there is priority set for node
    //pole = 1; //L-R, 1 2 3{} one is starting position
    //data = NULL;//data field set to a default value. Might not use this data field but wouldn't hurt.
    ptr = NULL;//points to nothing
}

template<class T>
node<T>::node()//constructor calls nFresh
{
    nFresh();
}

template<class T>
node<T>::~node()//destructor calls nFresh
{
    nFresh();
}

template<class T>
node<T>::node(T arg)//single arguement constructor
{
    priority = arg;
    ptr = NULL;
}

template<class T>
node<T>::node(node *other)//copy constructor
{
    priority = other->priority;
    //pole = other->pole;
    ptr = other->ptr;
}

template<class T>
node<T>& node<T>::operator=(node *other)
{
    priority = other->priority;
    ptr = other->ptr;

    return *this;
}

#endif // NODE_H
