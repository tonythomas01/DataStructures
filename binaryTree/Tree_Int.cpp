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

Node<int>* Tree_Int::get_root() {
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

void Tree_Int::inorder(Node<int> *node_ptr, ostream& out = cout)   {
  if ( node_ptr == NULL ) {
  return;
  } else {
    inorder( node_ptr->get_left());
    cout<< node_ptr->get_data()<< "  ";
    inorder(  node_ptr->get_right() );
  }
  return;
}

/* Second version*/
void Tree_Int::inorder(ostream& out = cout)   {
  inorder(this->get_root());
}


void Tree_Int::search( int value ) {
  Node<int>* ptr = root;
  search_helper( ptr, value );
//  cout<< ans->get_data();
}
Node<int>* Tree_Int::search_helper( Node<int>* ptr, int value )  {
  Node<int>* current_node = get_root();
  Node<int>* ret_node = NULL;
  if ( current_node->get_data() == value )  {
    ret_node = current_node;
  } else if ( current_node->get_data() < value )  {
    ret_node = search_helper( ptr->get_right(), value);
  } else if ( current_node->get_data() > value )  {
    ret_node = search_helper( ptr->get_left(), value );
  }
  return ret_node;
}




