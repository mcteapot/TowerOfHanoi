#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "TNode.h"

using namespace std;



template<typename T>
class Stack {
public:
	Stack(int size = 5);
	~Stack();
	Stack<T>& operator=(Stack<T> &other);

	void clear(); //Dump stack
	int size(); //How many itmes in the stack
	int getStackSize(); //returns the stack size
	void resize(int size); //Reize stack
	
	bool push(T data); //Push data on stack
	bool pop(); //Pop data off stack 

	T peek(); //See first item in stack
	bool isEmpty(); //Is stack empty
	bool isFull(); //Is stack full
	//std functions
	bool empty();
	T top();
	
private:
	TNode<T> *head;
	int stackSize, stackQty;
	void copy(Stack<T> &other);
	void recurse(Stack<T> *ptr);

};

//constrcutor
template<typename T>
Stack<T>::Stack(int size)
{
	stackSize = size;
	stackQty = 0;
	head = NULL;

}
//desctructor
template<typename T>
Stack<T>::~Stack()
{
   clear();                 
}

//overload operator =
template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> &other) {
	if(this != &other)
		copy(other);
	return *this;	
}

//clear
template<typename T>
void Stack<T>::clear() {
	if (stackSize) {
		TNode<T> *temp;
		while (head) {
			temp = head;
			head = head->next;
			delete temp;
		}
		head = NULL;
		stackSize = 0;
		stackQty = 0;
	}

}

//size
template<typename T>
int Stack<T>::size() {
	return stackQty;
}

//getStackSize
template<typename T>
int Stack<T>::getStackSize() {
	return stackSize;
}

//resize
template<typename T>
void Stack<T>::resize(int size) {
	clear();
	stackSize = size;
}
//push
template<typename T>
bool Stack<T>::push(T data) {
	if (!(isFull())) {
		TNode<T> *temp = new TNode<T>(data);
		temp->next = head;
		head = temp;
		stackQty++;
		return true;
	} else {
		return false;
	}
	
}
//pop
template<typename T>
bool Stack<T>::pop() {
	if (!(isEmpty())) {
		TNode<T> *temp = head;
		head = head->next;
		delete temp;
		stackQty--;
		return true;
	} else {
		return false;
	}
}

//isEmpty
template<typename T>
bool Stack<T>::isEmpty() {
	if(stackQty == 0) {
		return true;
	} else {
		return false;
	}	
} 
//isFull
template<typename T>
bool Stack<T>::isFull() {
	if(stackQty == stackSize) {
		return true;
	} else {
		return false;
	}
}
//empty
template<typename T>
bool Stack<T>::empty() {
	if(stackQty == 0) {
		return true;
	} else {
		return false;
	}	
}
//top
template<typename T>
T Stack<T>::top() {
	if (!(isEmpty())) {
		return head->data;
	} else {
		return NULL;
	}	
	
}

//copy
template<typename T>
void Stack<T>::copy(Stack<T> &other) {
	stackSize = other.stackSize;
	stackQty = other.stackQty;
	head = NULL;
	recurse(other.head);
}
//recurse
template<typename T>
void Stack<T>::recurse(Stack<T> *ptr) {
	if (!ptr) {
		recurse(ptr->next);
	}
	push(ptr->data);
}



#endif //STACK_H

