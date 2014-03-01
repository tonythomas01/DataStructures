#include "Tree_Int.h"
#include<iostream>

using namespace std;

Tree_Int::Tree_Int()
{
    root = NULL;
    tree_size = 0;
}
void  Tree_Int::insert (int x)  {
    Node<int> *temp = root;

    if (tree_size == 0) {
      temp = new Node<int>(x);
      root =temp;
      tree_size++;
      return;
    }
    while (!is_leaf(temp))  {
    if( x> temp->get_data() ) {
      if ( temp->right != NULL) {
      temp = temp->right;
      }
      break;
    }
    else if ( x< temp-> get_data() )  {
      if (temp->left != NULL) {
        temp = temp->left;
      }
      break;
    }
    else {
      cout<<"\n Cant insert as duplicate found";
      return;
    }
   }
    /* To insert the node  at the position showed by temp*/
    Node<int> * newNode = new Node<int>(x);
    if ( temp->get_data() > x ) {
      temp->left = newNode;
      ++tree_size;
    } else if ( temp->get_data() < x) {
      temp->right = newNode;
      ++tree_size;
    }
    return;
}

size_t Tree_Int::size() const {
    return tree_size;
}

bool Tree_Int::empty() const {
  return (tree_size == 0);
}

Node<int>* Tree_Int::get_root() const {
        return root;
}

bool Tree_Int::is_leaf(Node<int>* node) {
  if ( (node->get_left() == NULL) && (node->get_right()== NULL) ) {
    return 1;
  } else return 0;
}

/*Traversing the tree using inorder traversal scheme. The first version
traverses the tree from any particular node and the second version traverses
from the root node.*/
/*
void inorder (Node<int> *node_ptr, ostream& out = cout) const  {

  return;
}

/* Second version
void inorder(ostream& out = cout) const;
*/



