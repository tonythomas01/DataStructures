#include "Iterator_Node.h"

Node Iterator_Node::operator ++ () {
  node_ptr = node_ptr->get_next_ptr();
  return (*node_ptr);
}

Node* Iterator_Node::get_node_ptr()  {
  return node_ptr;
}

Node Iterator_Node::operator ++ (int) {
  Node *temp_ptr = this->node_ptr;
  node_ptr = node_ptr->get_next_ptr();
  return (*temp_ptr);
}

Node& Iterator_Node::operator--()  {
  assert(this->node_ptr!= NULL);
  assert(this->node_ptr->get_prev_ptr()!= NULL);
  assert(this->node_ptr->get_prev_ptr() != NULL);

  node_ptr = node_ptr->get_prev_ptr();
  return (*node_ptr);
}
