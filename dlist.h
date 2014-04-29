// copy this file to "dlist.h" and then modify it where specified below
#ifndef __DLIST_H__
#define __DLIST_H__
#include <cstddef>
#include <cassert>

/***************************************
 * Do not modify the class declarations!
 ***************************************/
template <typename T>
class Dlist {
  //OVERVIEW: a doubly-linked list
 public:

  //EFFECTS:  returns true if the list is empty
  bool isEmpty() const;

  //MODIFIES: this
  //EFFECTS:  inserts datum into the front of the list
  void insertFront(const T &datum);

  //MODIFIES: this
  //EFFECTS:  inserts datum into the back of the list
  void insertBack(const T &datum);

  //REQUIRES: list is not empty
  //MODIFIES: this
  //EFFECTS:  removes the item at the front of the list
  T removeFront();

  //REQUIRES: list is not empty
  //MODIFIES: this
  //EFFECTS:  removes the item at the back of the list
  T removeBack();

  Dlist();                                   // ctor
  Dlist(const Dlist &l);                     // copy ctor
  Dlist &operator=(const Dlist &l);          // assignment
  ~Dlist();                                  // dtor

 private:
  struct Node {                              // A private type
    Node   *next;
    Node   *prev;
    T      datum;
  };

  Node   *first; // The pointer to the first node (0 if none)
  Node   *last;  // The pointer to the last node (0 if none)

  //MODIFIES: this
  //EFFECTS:  copies all nodes from l to this
  void copyAll(const Dlist &l);

  //MODIFIES: this
  //EFFECTS:  removes all nodes
  void removeAll();
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/


/***************************************
 * Member function implementations here
 ***************************************/
template <typename T>
bool Dlist<T>::isEmpty() const {
	return !first;
}

template <typename T>
void Dlist<T>::insertFront(const T &datum){
	Node *node = new Node; 
	node->datum = datum; 
	node->next = first;
	node->prev = 0;
	if(!isEmpty()) first->prev = node;
	if(isEmpty()) last = node;
	first = node;
}

template <typename T>
void Dlist<T>::insertBack(const T &datum){
	Node *node = new Node;
	node->datum = datum;
	node->next = 0;
	node->prev = last;
	if(!isEmpty()) last->next = node;
	if(isEmpty()) first = node;
	last = node;
}

template <typename T>
T Dlist<T>::removeFront(){
	assert(!isEmpty());
	
	Node * temp = first; // Holds pointer to the node being removed
	T value = (first->datum); // Holds datum of the node being removed
	if(first == last) last = 0; // It there is only one node in the list
	else (first->next)->prev = 0; // Prev of new first node = 0
	first = first->next; // move first pointer
	
	delete temp; temp = 0; 
	return value;
}

template <typename T>
T Dlist<T>::removeBack(){
	assert(!isEmpty());
	
	Node * temp = last; // Holds pointer to the node being removed
	int value = last->datum; // Holds datum of the node being removed
	(last->prev)->next = 0; // next of new last node = 0
	if(first == last) first = 0; // It there is only one node in the list
	last = last->prev; // move first pointer
	
	delete temp; temp = 0; 
	return value;
}

template <typename T>
Dlist<T>::Dlist() : first(0), last(0) {}

template <typename T>
Dlist<T>::Dlist(const Dlist &l): first(0), last(0) {
	copyAll(l);
}

template <typename T>
Dlist<T> & Dlist<T>::operator=(const Dlist &l){
	if(this == &l) return *this;
	removeAll();
	copyAll(l);
	return *this;
}

template <typename T>
Dlist<T>::~Dlist(){
	removeAll();
}

template <typename T>
void Dlist<T>::copyAll(const Dlist &l){
	for(Node * node = l.first; node; node = node->next){
		insertBack(node->datum);
	}
}

template <typename T>
void Dlist<T>::removeAll(){
	while(!isEmpty()){
		removeFront();
	}
}



/* this must be at the end of the file */
#endif /* __DLIST_H__ */
