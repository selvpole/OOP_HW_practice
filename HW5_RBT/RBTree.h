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
};

//  RBTree

class RBTree{
public:
  // Constructor
  RBTree() {root = NULL;}
  bool insert(int n, const string gd, int h, int w);
  string getGender(){return root->gender;}
  int getHeight(){return root->height;}
  int getWeight(){return root->weight;}
  void setRoot(Node *node){*root = *node;}
public:
  // operator
  RBTree &operator[](int key);
  const RBTree operator[](int key)const;

protected:
  void rotateLeft(Node *&, Node *&);
  void rotateRight(Node *&, Node *&);
  void fixViolation(Node *&, Node *&);
private:
  Node *root;
};


#endif
