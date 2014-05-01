#pragma once
#include<iostream>
using namespace std;
void Tree_Int::insert(int d)  {
  if ( tree_size == 0 ) {
    Node* node = new Node(d);
    root = node;
    ++tree_size;
    return;
  } else {
  Node* temp = root;
  Node* node = new Node(d);
  while (1) {
    if ( temp->get_data() < d ) {
      if ( temp->get_right() == NULL )  {
        temp->set_right(node);
        ++tree_size;
        return;
      } else  {
        temp = temp->get_right();
      }
    } else if ( temp->get_data()>d ) {
      if ( temp->get_left() == NULL ) {
        temp->set_left(node);
        ++tree_size;
        return;
      } else {
        temp = temp->get_left();
      }
    } else {
      cout<< " Duplicate element found ";
      break;
    }
  }
  return;
  }
}

void Tree_Int::inorder_traversal(fstream& out)  {
  Node* node = root;
  inorder_traversal(root, out);

}
void Tree_Int::inorder_traversal( Node* node , fstream& out) {
  if ( node == NULL ) {
    return;
  } else {
  inorder_traversal(node->get_left(), out);
  out<<node->get_data()<< "->";
  inorder_traversal(node->get_right(), out);
  }
}
