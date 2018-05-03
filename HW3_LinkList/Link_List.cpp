#include <iostream>
#include "Link_List.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ostream;
using std::istream;


/*---------------Construct Int_Node----------------*/

template<typename T>
Int_Node<T>::Int_Node() : value(0), pre(NULL), next(NULL){};

template<typename T>
Int_Node<T>::Int_Node(T val) : value(val), pre(NULL), next(NULL){}

/*---------------operator cin & cout---------------*/

template<typename T>
ostream &operator<<(ostream &cout, const Link_List<T> &list){
  for(int i=0; i<list.getSize(); i++){
    cout << list[i] << " ";
  }
  return cout;
}

template<typename T>
istream &operator>>(istream &cin, Link_List<T> &list){
  T input;
  cin >> input;
  list.insert_node(input);
  return cin;
}

/*-------------constructor & destructor-----------*/

template<typename T>
Link_List<T>::Link_List() : size(0), head(NULL), tail(NULL){}

template<typename T>
Link_List<T>::Link_List(const Link_List<T> &list){
  *this = list;
}

template<typename T>
Link_List<T>::~Link_List(){
  delete head;
  delete tail;
}

/*--------------------functoin--------------------*/

template<typename T>
int Link_List<T>::getSize() const{
  return size;
}

template<typename T>
const Link_List<T> &Link_List<T>::operator=(const Link_List<T> &list){
  Int_Node<T> *curNode = list.head;
  Int_Node<T> *newHead = NULL;
  Int_Node<T> *newTail = NULL;

  while(curNode != NULL){
    Int_Node<T> *newNode = new Int_Node<T>(curNode->value);

    if(newHead == NULL){
      newHead = newNode;
      newTail = newNode;
    }
    else{
      newTail->next = newNode;
      newNode->pre = newTail;
      newTail = newTail->next;
    }
    curNode = curNode->next;
  }

  // this->clear_list();

  this->head = newHead;
  this->tail = newTail;
  this->size = list.getSize();
}

template<typename T>
bool Link_List<T>::operator==(const Link_List<T> &list) const{
  if(this->size != list.getSize())
    return false;

  for(int i=0; i<this->size; i++){
    if((*this)[i] != list[i])
      return false;
  }
  return true;
}

template<typename T>
T &Link_List<T>::operator[](int index){
  if(index >= size || index < 0){
    cerr << "\nError: index " << index
    << " out of range" << endl;
    exit(1); // terminate program; index out of range
  }
  else{
    Int_Node<T> *curNode = this->head;
    for(int i=0; i<index; i++)
      curNode = curNode->next;

    return curNode->value;
  }
}

template<typename T>
T Link_List<T>::operator[](int index) const{
  if(index >= this->size || index < 0){
    cerr << "\nError: index " << index
    << " out of range" << endl;
    exit(1); // terminate program; index out of range
  }
  else{
    Int_Node<T> *curNode = this->head;
    for(int i=0; i<index; i++)
      curNode = curNode->next;

    return curNode->value;
  }
}

template<typename T>
bool Link_List< T >::insert_node(T value){
  try{
    Int_Node<T> *newNode = new Int_Node<T>(value);
    if(size == 0){
      this->head = newNode;
      this->tail = newNode;
    }
    else{
      this->tail->next = newNode;
      this->tail->next->pre = this->tail;
      this->tail = this->tail->next;
    }
    size++;
    return true;
  }
  catch(...){
    return false;
  }
}

template<typename T>
bool Link_List< T >::insert_node(int index, T value){
  try{
    Int_Node<T> *newNode = new Int_Node<T>(value);
    Int_Node<T> *curNode = this->head;
    for(int i=0; i<index;i++){
      curNode = curNode->next;
    }
    curNode->pre->next = newNode;   // cur -> new
    newNode->pre = curNode->pre;    // cur <- new
    newNode->next = curNode;        // new -> curNext
    curNode->pre = newNode;         // new <- curNext
    size++;
    return true;
  }
  catch(...){
    return false;
  }
}

template<typename T>
bool Link_List<T>::delete_node(){
  try{
    Int_Node<T> *curNode = this->tail;
    curNode->pre->next = NULL;
    delete curNode;
    this->size--;
    return true;
  }
  catch(...){
    return false;
  }
}

template<typename T>
bool Link_List<T>::delete_node(int index){
  try{
    Int_Node<T> *curNode = this->head;
    for(int i=0; i<index; i++)
      curNode = curNode->next;

    curNode->pre->next = curNode->next; // pre -> next
    curNode->next->pre = curNode->pre;  // pre <- next
    delete curNode;
    this->size--;
    return true;
  }
  catch(...){
    return false;
  }
}

// template<typename T>
// bool Link_List<T>::clear_list(){
//   try{
//     int i=0;
//     while(head != NULL){
//       cout << i++ << endl;
//       Int_Node<T> *tmp = this->tail;
//       tail = tail->pre;
//       delete tmp;
//     }
//     return true;
//   }
//   catch(...){
//     return false;
//   }
// }
