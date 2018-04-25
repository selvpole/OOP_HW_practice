#include <iostream>
#include "Link_List.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

/*---------------Construct Int_Node----------------*/
Int_Node::Int_Node(){
  this->value = 0;
  this->pre = NULL;
  this->next = NULL;
}

Int_Node::Int_Node(int val){
  this->value = val;
  this->pre = NULL;
  this->next = NULL;
}

/*---------------operator cin & cout---------------*/
ostream &operator<<(ostream &cout, const Link_List &list){
  for(int i=0; i<list.getSize(); i++){
    cout << list[i] << " ";
  }
  return cout;
}
istream &operator>>(istream &cin, Link_List &list){
  int input;
  cin >> input;
  list.insert_node(input);
  return cin;
}

/*-------------constructor & destructor-----------*/

Link_List::Link_List() : size(0), head(NULL), tail(NULL){}

Link_List::Link_List(const Link_List &list){
  *this = list;
}

Link_List::~Link_List(){
  delete head;
  delete tail;
}

/*--------------------functoin--------------------*/

int Link_List::getSize() const{
  return size;
}

const Link_List &Link_List::operator=(const Link_List &list){
  Int_Node *newHead=list.head;
  Int_Node *newTail=NULL;
  Int_Node *curNode = list.head;
  
  while(curNode != NULL){
    if(newTail == NULL){
      newTail = curNode;
    }
    else{
      newTail->next = curNode;
      newTail->next->pre = newTail;
      newTail = newTail->next;
    }

    curNode = curNode->next;
  }

  this->head = newHead;
  this->tail = newTail;
  this->size = list.getSize();
}

bool Link_List::operator==(const Link_List &list) const{
  if(this->size != list.getSize())
    return false;
  Int_Node *n1 = this->head;
  Int_Node *n2 = list.head;

  while(n1 != NULL && n2 != NULL){
    if(n1->value != n2->value)
      return false;
    n1 = n1->next;
    n2 = n2->next;
  }
  return true;
}

int &Link_List::operator[](int index){
  if(index >= size || index < 0){
    cerr << "\nError: index " << index
    << " out of range" << endl;
    exit(1); // terminate program; index out of range
  }
  else{
    Int_Node *curNode = this->head;
    for(int i=0; i<index; i++)
      curNode = curNode->next;

    return curNode->value;
  }
}

int Link_List::operator[](int index) const{
  if(index >= this->size || index < 0){
    cerr << "\nError: index " << index
    << " out of range" << endl;
    exit(1); // terminate program; index out of range
  }
  else{
    Int_Node *curNode = this->head;
    for(int i=0; i<index; i++)
      curNode = curNode->next;

    return curNode->value;
  }
}

bool Link_List::insert_node(int value){
  try{
    Int_Node *newNode = new Int_Node(value);
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
  catch(int err){
    return false;
  }
}

bool Link_List::delete_node(){
  try{
    Int_Node *curNode = this->tail;
    curNode->pre->next = NULL;
    delete curNode;
    this->size--;
    return true;
  }
  catch(int err){
    return false;
  }
}

bool Link_List::insert_node(int index, int value){
  try{
    Int_Node *newNode = new Int_Node(value);
    Int_Node *curNode = this->head;
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
  catch(int err){
    return false;
  }
}

bool Link_List::delete_node(int index){
  try{
    Int_Node *curNode = this->head;
    for(int i=0; i<index; i++)
      curNode = curNode->next;

    curNode->pre->next = curNode->next; // pre -> next
    curNode->next->pre = curNode->pre;  // pre <- next
    delete curNode;
    this->size--;
    return true;
  }
  catch(int err){
    return false;
  }
}
