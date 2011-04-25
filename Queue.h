
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <cmath>

#include "Node.h"

using namespace std;
//NOTE: THE HIGHER THE PRIORITY NUMBER, THE HIGHER IT'S PRIORITY ALSO THE NEWEST IT IS.
//      THE LOWER THE PRIORITY NUMBER THE OLDER THE DISK IS ON THE POLE AND THE LOWER ITS
//      PLACE IS IN THE QUEUE.

template<class T>
class Queue
{
public:
    //NOTE: when creating an instance of a pole other than pole #1,
    //      use single arguement constructor... i.e B(A), C(A) and put A as arguement.
    //NOTE: for pole #1, create the instance with the size the user enters
    //      as its arguement ... A(size). and THEN CREATE it using the create()
    //      function. i.e A.create();  this will fill up the first pole
    //      for gameplay. Refer to main.cpp for more examples...

    Queue();//default constructor
    Queue(int size);
    ~Queue();//destructor

    //Queue(Queue& other);
    Queue& operator=(Queue& other);


    //void copy(Queue& other);
    void fresh();//sets variables to 0 and ptrs to null.
    void display();//prints out all elements in queue
    void create();//creates first list at pole 1 with desired number of disks
    Queue(Queue &object);//Gets the number of disks user enters from object A and assigns to
                                //newly created object... Sets standard number of disks available
                                //at any time in game play to all poles (rods) and assigns it.

    T front(); // newest node in queue
    T top();
    int disks();//accessor of private variable qty. Total disks in play. User input.
    T back();//oldest node in queue
    int size();//returns size of queue
    T prev();//returns node 2nd node from the back(). second disk down from top of pole



    void enqueue(T item);
    void dequeue();
    void push(T item);
    void pop();
    void clear();

    bool search(T item);//returns true if node exists in queue
    bool isEmpty();//returns true if queue is empty
    bool empty();//calls isEmpty() and returns bool
    bool isFull();//returns true if queue is full
    bool checks(T item); //test


private:
    int count, qty;//count is the number or nodes on pole and qty is the number of disks in game
    static int temp; //"size"
    node<T> *low, *high, *entry, *newnode;//points of type node to help walk link list and etc

    void deLinkList();//destroys link list
    void initQueue();//initialize link list

};
template<class T>
int Queue<T>::temp = 0;//done

template<class T>
T Queue<T>::back()//done
{
    entry = low;
    assert(entry != NULL);
    entry = entry->ptr;
    return entry->priority;
}

template<class T>
T Queue<T>::front()//done
{
    if(low != NULL)
    {
    assert(high != NULL);
    return high->priority;
    }
    return 0;
/* ALTERNATE CODE FOR ABOVE...
    {
    int temp = 0;

    entry = low->ptr;
    for(entry=entry->ptr; entry->ptr != NULL; entry = entry->ptr)
        temp = entry->priority;

    return temp;
    }
 */
}
template<class T>
void Queue<T>::fresh()
{
    low = NULL;
    high = NULL;
    newnode = NULL;
    entry = NULL;
    count = 0;
    qty = 0;
}
template<class T>
Queue<T>::Queue()//done
{
    low = new node<T>;
    low->ptr = NULL;
    high = low;
    count = 0;
    qty = 0;
    initQueue();
}
template<class T>
Queue<T>::Queue(int size)//done
{
    low = new node<T>;
    low->ptr = NULL;
    high = low;
    qty = size;
    count = 0;
    initQueue();
}

template<class T>
Queue<T>::Queue(Queue &object)//done
{
    low = new node<T>;
    low->ptr = NULL;
    high = low;
    count = 0;
    initQueue();
    qty = object.disks();
}

template<class T>
int Queue<T>::disks()
{
    return qty;
}

template<class T>
T Queue<T>::top()
{
    return front();
}

template<class T>
void Queue<T>::initQueue()//done
{

    newnode = new node<T>;
    //newnode->priority = 0;
    newnode->ptr = NULL;
    high->ptr = newnode;
    high = newnode;
    low = newnode;
}

template<class T>
Queue<T>::~Queue()
{
    //fresh();
    deLinkList();
}

template<class T>
void Queue<T>::create()//done
{
    for(int k = qty; k > 0; k--)
    {
     newnode = new node<T>;
     newnode->priority = k;
     newnode->ptr = NULL;
     high->ptr = newnode;
     high = newnode;
    }
}

template<class T>
void Queue<T>::deLinkList()
{
    node<T> *current, *tmp;

    current = low->ptr;
    low->ptr = NULL;
   while(current != NULL)
   {
       tmp = current->ptr;
       delete(current);
       current = tmp;
   }
   high = NULL;
   count = 0;
   qty = 0;
}

template<class T>
void Queue<T>::enqueue(T item)//done
{
    //if(check(item))
    //{
        node<T> *temp;
     temp = new node<T>;
     temp->priority = item;
     temp->ptr = NULL;

     high = low;
     while(high->ptr != NULL)
     {
        high = high->ptr;
     }

        if(high->ptr == NULL)
        {
            high->ptr = temp;
            high = temp;
            count++;
            qty++;
        //cout << "Successfull enqueue!\n";
        }

     //else
     //cout << "Enqueue unsuccessful!\n";
    //}
        //else
            //cout << "full or disk already exists\n";
}

template<class T>
void Queue<T>::pop()//done
{
    dequeue();
}

template<class T>
void Queue<T>::push(T item)//done
{
    enqueue(item);
}

template<class T>
void Queue<T>::clear()
{
    deLinkList();
}

template<class T>
void Queue<T>::dequeue()//done
{
    if(checks(-2))
 {
    node<T> *next;

    high = low;
    //system("pause");
    next = high->ptr;
    while(next->ptr != NULL)
    {
        high = high->ptr;
        next = next->ptr;
    }
    if(next->ptr == NULL)
    {
        temp = next->priority;
        high->ptr = next->ptr;
        count--;
        qty--;
        delete next;
    }

    //cout << "Dequeue Successful!\n";}
    //else
    //cout << "Dequeue unsuccessful!\n";
 }

    //else
       // cout << "Dequeue Empty\n";

}

template<class T>
int Queue<T>::size()//done
{
    count = 0;
    entry = low->ptr;
    if(low->ptr != NULL)
    {
        //cout << "beore assignment\n";
        //entry = low->ptr;
        //cout << "outside while loop\n";
    while(entry != NULL)
        {
            entry = entry->ptr;
            ++count;
        }
    }
    else
        ;
        //cout << "low->ptr = NULL " << endl;

    return count;
}

template<class T>
bool Queue<T>::search(T item)//done
{
    node<T> *entry;

    entry = new node<T>;
    entry = low->ptr;
    while(entry != NULL && item != entry->priority)
        entry = entry->ptr;
    if (entry == NULL)
    {
        delete entry;
        return false;
    }
    else
        delete entry;
        return true;
}

template<class T>
void Queue<T>::display()//done
{
    //if(checks(-3))
    //{
        //cout << "Queue for pole is ...\n";
        entry = low->ptr;
        while(entry != NULL)
        {
         cout << "Priority: " << entry->priority << endl;
         entry = entry->ptr;
        }
    //}
    //else
        //cout << "empty\n";
}

template<class T>
bool Queue<T>::isEmpty()//done
{
    if (size() == 0)
        return true;
    return false;
}

template<class T>
bool Queue<T>::empty()
{
    return isEmpty();
}

template<class T>
bool Queue<T>::isFull()//done
{
    return (size() == qty);
}

template<class T>
bool Queue<T>::checks(T item)//done. Works like a switch statement. item is a function code.
{
    if (item == -2 && !isEmpty()) { //if -2 is passed, then calling
        return true;                //from the dequeue function or prev or somethin else.
	}
    else if(item == -3 && size() > 0) { //meant for prev function
        return true;
	}
    else if(item == -4 && front() < prev()) {// code (-4) is used for comparing
        return true;                      //priorities amongst the queue. true if disk to
                                          //be added is smaller than the one already there.
	}
    else if(!isFull() && item > 0 && !search(item))  { //calling from enqueue function
        return true;
	}
    else{
        return false;
	}
}

template<class T>
T Queue<T>::prev()//function code (-3). done
{
    if(checks(-3))
    {
        node<T> *current;
        high = low;
        current = high->ptr;
        while(current->ptr != NULL)//in here, current is the leader and high is following one behind...
        {                        //  so if current->ptr == NULL then current is the last node and is
            high = high->ptr;   //   represented by back(). high is then the node one below in priority.
            current = current->ptr;
        }
        return high->priority;
    }
    else
        return -3;
}

#endif // QUEUE_H
