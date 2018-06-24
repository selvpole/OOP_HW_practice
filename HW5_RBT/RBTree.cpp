#include <iostream>
#include "RBTree.h"

using namespace std;

/*---------- constuctor of Node ----------*/

Node::Node(int k, const string gd, int h, int w)
  :key(k), gender(gd), height(h), weight(w){;}

/*--------------------- RBT ---------------------*/


bool RBTree::insert(int k, const string gd, int w, int h)
{
  try{
    Node *pt = new Node(k, gd, w, h);

    root = BSTInsert(root, pt);

    fixViolation(root, pt);

    return true;
  }
  catch(...){
    return false;
  }
}

//  operator []

RBTree &RBTree::operator[](int key){
  RBTree tmpTree;
  Node *cur == root;
  while(cur->key != key && cur != NULL){
    if(cur->key > key)
      cur = cur->left;
    else
      cur = cur->right;
  }
  tmpTree.setRoot(*cur);
  return tmpTree;
}

const RBTree RBTree::operator[](int key) const{
  RBTree tmpTree;
  Node *cur == root;
  while(cur->key != key && cur != NULL){
    if(cur->key > key)
      cur = cur->left;
    else
      cur = cur->right;
  }
  tmpTree.setRoot(*cur);
  return tmpTree;
}

// outside function for RBTree_insert

Node *BSTInsert(Node *root, Node *pt)
{
  //  If the tree is empty, insert a new Node
  if(root == NULL)
    return pt;

  //  Otherwise, recur down the tree
  if(pt->key < root->key)
  {
    root->left = BSTInsert(root->left, pt);
    root->left->parent = root;
  }
  else if(pt->key > root->key)
  {
    root->right = BSTInsert(root->right, pt);
    root->right->parent = root;
  }

  return root;
}

//  protected function

void RBTree::rotateLeft(Node *&root, Node *&pt)
{
  Node *pt_right = pt->right;

  pt->right = pt_right->left;

  if(pt->right != NULL)
    pt->right->parent = pt;

  pt_right->parent = pt->parent;

  if(pt->parent == NULL)
    root = pt_right;
  else if(pt == pt->parent->left)
    pt->parent->left = pt_right;
  else
    pt->parent->right = pt_right;

  pt_right->left = pt;
  pt->parent = pt_right;
}

void RBTree::rotateRight(Node *&root, Node *&pt)
{
  Node *pt_left = pt->left;

  pt->left = pt_left->right;

  if(pt->left != NULL)
    pt->left->parent = pt;

  pt_left->parent = pt->parent;

  if(pt->parent == NULL)
    root = pt_left;
  else if(pt->parent->left == pt)
    pt->parent->left = pt_left;
  else
    pt->parent->right = pt_left;

  pt_left->right = pt;
  pt->parent = pt_left;
}

// BSTree insertion
void RBTree::fixViolation(Node *&root, Node *&pt)
{
  Node *parent_pt = NULL;
  Node *grand_parent_pt = NULL;

  while((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
  {
    parent_pt = pt->parent;
    grand_parent_pt = pt->parent->parent;

    /*  Case A:
        parent at grandparent's left
    */
    if(parent_pt == grand_parent_pt->left){
      Node *uncle_pt = grand_parent_pt->right;

      /*  Case 1:
          uncle is also RED
      */
      if(uncle_pt != NULL && uncle_pt->color == RED)
      {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      }

      else
      {
        /*  Case 2:
        pt is right child of its parent
        Left-rotation requiRED
        */
        if(pt == parent_pt->right)
        {
          rotateLeft(root, parent_pt);
          pt = parent_pt;
          parent_pt = grand_parent_pt;
        }

        /*  Case 3:
        pt is left child of its parent
        Left-rotation requiRED
        */
        rotateRight(root, grand_parent_pt);
        swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }

    /*  Case B:
        parent at grandparent's right
    */
    else
    {
      Node *uncle_pt = grand_parent_pt->left;

      /*  Case 1:
          uncle also RED
      */
      if((uncle_pt != NULL) && (uncle_pt->color == RED))
      {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      }

      else
      {
        /*  Case 2:
            pt at parent's Left
        */
        if(pt == parent_pt->left)
        {
          rotateRight(root, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }

        /*  Case 3:
            pt at parent's pt_right
        */
        rotateLeft(root, grand_parent_pt);
        swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
  }
  root->color = BLACK;
}
