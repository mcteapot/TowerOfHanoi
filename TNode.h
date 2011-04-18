#ifndef TNODE_H
#define TNODE_H

#include <cstdlib>
#include <iostream>

using namespace std;

//template<class T>
template<typename T>
struct TNode {
	T data;
	TNode* next;
	
	TNode();
	//TNode(T d);
	//TNode(TNode<T> *ptr);
	TNode(T d = NULL, TNode<T> *ptr = NULL);
	~TNode(); 
	bool last();  
	
	TNode& operator=(TNode& other);    
	
};


/*
template<typename T>
TNode<T>::TNode() {
	data = (T)NULL; 
	next = NULL;
}


template<typename T>
TNode<T>::TNode(T d) {
	data = d;
	next = NULL;
}


template<typename T>
TNode<T>::TNode(TNode<T> *ptr) {
	data = ptr->data;
	next = NULL;
	
}
 */
template<typename T>
TNode<T>::TNode(T d, TNode<T> *ptr) {
	data = d;
	next = ptr;
	
}

template<typename T>
TNode<T>::~TNode() {
	next = NULL;
	data = (T)NULL;
} 


template<typename T>
bool TNode<T>::last() {
	return !next; 
}  


template<typename T>
TNode<T>& TNode<T>::operator=(TNode& other) {
	data = other->data;
	next = NULL;
	return *this;
}    

#endif //TNODE