#include <iostream>
#include <string.h>
#include "RBTree.h"

using namespace std;

/*--------------- constuctor of Node ---------------*/

Node::Node(int k, const string gd, int h, int w)
  :key(k), gender(gd), height(h), weight(w){;}

/*--------------------- RBT ---------------------*/

//  operator []

Node &RBTree::operator[](int key){
  Node *cur = root;
  while(cur->key != key && cur != NULL){
    if(cur->key > key)
      cur = cur->left;
    else
      cur = cur->right;
  }
  return *cur;
}

const Node RBTree::operator[](int key) const{
  Node *cur = root;
  while(cur->key != key && cur != NULL){
    if(cur->key > key)
      cur = cur->left;
    else
      cur = cur->right;
  }
  return *cur;
}

// outside function for RBTree_insert

bool RBTree::insert(int key, const string gender, int height, int weight)
{
  try{
    Node *pt = new Node(key, gender, height, weight);
    Node *cur = root;
    Node *pre = NULL;

    while(cur != NULL){
      // check if the new key has already existed
      if(pt->key == cur->key)
        return false;

      pre = cur;
      if(pt->key > cur->key)
        cur = cur->right;
      else
        cur = cur->left;
    }

    if(pre == NULL)
      root = pt;
    else{
      if(pt->key > pre->key)
        pre->right = pt;
      else
        pre->left = pt;
    }
    pt->parent = pre;
    pt->color = RED;

    fixViolation(pt);

    return true;
  }
  catch(...){
    cerr << "error when inserting !" << endl;
    return false;
  }
}

//  protected function

void RBTree::rotateLeft(Node *&pt)
{
  Node *pt_right = pt->right;

  if(pt->parent == NULL)
    root = pt_right;
  else if(pt == pt->parent->left)
    pt->parent->left = pt_right;
  else
    pt->parent->right = pt_right;

  pt_right->parent = pt->parent;
  pt->right = pt_right->left;
  pt_right->left->parent = pt;
  pt_right->left = pt;
  pt->parent = pt_right;
}

void RBTree::rotateRight(Node *&pt)
{
  Node *pt_left = pt->left;

  if(pt->parent == NULL)
    root = pt_left;
  else if(pt->parent->left == pt)
    pt->parent->left = pt_left;
  else
    pt->parent->right = pt_left;

  pt_left->parent = pt->parent;
  pt->left = pt_left->right;
  pt_left->right->parent = pt;
  pt_left->right = pt;
  pt->parent = pt_left;
}

// BSTree insertion
void RBTree::fixViolation(Node *&pt)
{
  Node *parent_pt = NULL;
  Node *grand_parent_pt = NULL;

  while((pt != NULL) && (pt->color != BLACK) && (pt->parent->color == RED))
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
        Left-rotation required
        */
        if(pt == parent_pt->right)
        {
          rotateLeft(parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }

        /*  Case 3:
        pt is left child of its parent
        Right-rotation requiRED
        */
        rotateRight(grand_parent_pt);
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
          rotateRight(parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }

        /*  Case 3:
            pt at parent's pt_right
        */
        rotateLeft(grand_parent_pt);
        swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
  }
  root->color = BLACK;
}
