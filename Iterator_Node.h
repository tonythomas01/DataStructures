#ifndef ITERATOR_NODE_H
#define ITERATOR_NODE_H
#include<iostream>
#include "Node.h"
#include<cassert>

using namespace std;

class Iterator_Node
{
  private:
    Node *node_ptr;
  public:
    Iterator_Node(Node *p):node_ptr(p)  {}
    int& operator *() {
      assert(this->node_ptr != NULL);
      assert(this->node_ptr->get_next_ptr()!= NULL);
      return node_ptr->data;
    }
    Node* operator ->() {
      assert(node_ptr != NULL);
      return node_ptr;
    }
    bool operator == (const Iterator_Node& i) {
      return (this->node_ptr == i.node_ptr);
    }
    bool operator != (const Iterator_Node& i) {
      return !(*this == i);
    }
    Node operator++(int);
    Node operator++();
    Node* get_node_ptr();
    Node& operator--();


};
#include "Iterator_Node.cpp"


#endif // ITERATOR_NODE_H
