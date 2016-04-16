#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template<typename T>
class DoublyLinkedList; // class declaration

// list node
template<typename T>
class DListNode {
private:
  T obj;
  DListNode<T> *prev, *next;
  friend class DoublyLinkedList<T>;
public:
  DListNode(T e = T(), DListNode *p = NULL, DListNode *n = NULL)
    : obj(e), prev(p), next(n) {}
  T getElem() const { return obj; }
  DListNode<T> * getNext() const { return next; }
  DListNode<T> * getPrev() const { return prev; }
};

struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// doubly linked list
template<typename T>
class DoublyLinkedList {
protected:
  DListNode<T> header, trailer;
public:

  // constructor
  DoublyLinkedList<T>() : header(T()), trailer(T()){
    header.next = &trailer; trailer.prev = &header;
  }

  // copy constructor
  DoublyLinkedList(const DoublyLinkedList<T>& dll){
    // Initialize the list
    header.next = &trailer; trailer.prev = &header;

    // Copy from dll
    DListNode<T> *current = dll.getFirst();

    while (current != dll.getAfterLast()) {
      this->insertLast(current->getElem());
      current = current->getNext();
    }
  }

  //destructor
  ~DoublyLinkedList(){
      DListNode<T> *prev_node, *node = header.next;
      while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
      }
      header.next = &trailer;
      trailer.prev = &header;
  }


  // assignment operator
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll){
    // Delete the whole list
    /* Complete this function */
    DListNode<T> *prev_node, *node = header.next;
    while (node != &trailer) {
      prev_node = node;
      node = node->next;
      delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;

    // Copy from dll
    /* Complete this function */
    DListNode<T> *current = dll.getFirst();

    while (current != dll.getAfterLast()) {
      this->insertLast(current->getElem());
      current = current->getNext();
    }
  }

  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; }

  DListNode<T> *getLast() const {return trailer.prev; }

  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; }

  // return if the list is empty
  bool isEmpty() const { return header.next == &trailer; }

  // return first object
  T first() const{
    if (isEmpty())
      throw EmptyDLinkedListException("Empty Doubly Linked List");
    return header.next->obj;
  }

  // return last object
  T last() const{
    if (isEmpty())
      throw EmptyDLinkedListException("Empty Doubly Linked List");
    return trailer.prev->obj;
  }



  // insert to the first of the list
  void insertFirst(T newobj){
    DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
  }

  // remove the first node
  T removeFirst(){
    if (isEmpty())
      throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    T obj = node->obj;
    delete node;
    return obj;
  }

  // insert to the last of the list
  DListNode<T>* insertLast(T newobj){
    DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
    return newNode;
  }

  // remove the last node
  T removeLast(){
    if (isEmpty())
      throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    T obj = node->obj;
    delete node;
    return obj;
  }

  DListNode<T> *insertOrderly(const T& obj){
  	if (isEmpty()){
  		DListNode<T> *newNode = new DListNode<T>(obj, &header,&trailer);
  		trailer.prev = newNode;
  		header.next = newNode;
  		return newNode;
  	}
  	else{
  		DListNode<T> *c = this->getFirst();
  		while(c != &trailer){
  			if (obj < c->getElem()){
  				DListNode<T> *newNode = new DListNode<T>(obj,c->prev,c);
  				c->prev->next = newNode;
  				c->prev = newNode;
  				return newNode;
  			}
  			else{
  				c = c->next;
  			}
  		}
  		return insertLast(obj);

  	}
  }

};

template<typename T>
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll){
  /* Complete this function */
    DListNode<T> *node = dll.getFirst();
  if(!dll.isEmpty()){
    while (node->getNext() != dll.getAfterLast()) {
      cout << node->getElem();
      node = node->getNext();
    }
      cout << node->getElem();
  }


  return out;
}

// insert an object to the correct position assuming the linked list is sorted
// template<typename T>
// DListNode<T>* DoublyLinkedList<T>::insertOrderly(const T& obj){
// 	if (isEmpty()){
// 		DListNode<T> *newNode = new DListNode<T>(obj, &header,header.next);
// 		header.next->prev = newNode;
// 		header.next = newNode;
// 		return newNode;
// 	}
// 	else{
// 		DListNode<T>* c = this.getFirst();
// 		while(c != getLast()){
// 			if (c->getElem() < c->next.getElem()){
// 				DListNode<T> *newNode = new DListNode<T>(obj,c->prev,c);
// 				prev->next = newNode;
// 				newNode->prev = prev;
// 				prev = newNode;
// 				newNode->next = c;
// 				return newNode;
// 			}
// 			else{
// 				c = c->next;
// 			}
// 		}
// 		return insertLast(obj);
//
// 	}
// };
