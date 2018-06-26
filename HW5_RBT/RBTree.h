#ifndef RBTREE_H
#define RBTREE_H

#include <string.h>

using std::string;

enum Color {RED, BLACK};

struct Node{
  int key;
  string gender;
  int height, weight;
  bool color;
  Node *left=NULL, *right=NULL, *parent=NULL;
  // Constructor
  Node(int key, const string gender, int height, int weight);
  // functions
  inline const string &getGender() const{return gender;}
  inline const int &getHeight()  const{return height;}
  inline const int &getWeight()  const{return weight;}
};

//  RBTree

class RBTree{
public:
  // Constructor
  RBTree() {root = NULL;}
  bool insert(int k, const string gd, int h, int w);
  // operator
  Node &operator[](int);
  const Node operator[](int)  const;

private:
  void rotateLeft(Node *&);
  void rotateRight(Node *&);
  void fixViolation(Node *&);

private:
  Node *root;
};


#endif
