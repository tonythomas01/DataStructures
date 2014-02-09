#include "List_double_ptr_Int.h"

void List_double_ptr_Int::print_reverse()  {
  if(empty()) {
    cout<<" LIST EMPTY"<<endl;
  } else {
    Node *temp = sentinal_tail.get_prev_ptr();
    while(temp!= &sentinal_head)  {
      cout<<temp->get_data()<< " ";
      temp=temp->get_prev_ptr();
    }
    cout<<endl;
  }
}

void List_double_ptr_Int::push_back(const int &d) {
  Node *node = new Node(d);
  if(this->size()==0) {
    sentinal_head.set_next_ptr(node);
    node->set_prev_ptr(&sentinal_head);
    sentinal_tail.set_prev_ptr(node);
    node->set_next_ptr(&sentinal_tail);
  } else {
    Node* temp = sentinal_tail.get_prev_ptr();
    temp->set_next_ptr(node);
    node->set_prev_ptr(temp);
    sentinal_tail.set_prev_ptr(node);
    sentinal_tail.set_prev_ptr(&sentinal_tail);
  }
  list_size++;
  return;
}
void List_double_ptr_Int::push_front(const int &d)  {
  if(this->size() == 0) {
    push_back(d);
  } else {
    Node *node = new Node(d);
    list_size++;

    Node *temp = sentinal_head.get_next_ptr();
    temp->set_prev_ptr(node);
    node->set_next_ptr(temp);
    node->set_prev_ptr(&sentinal_head);
    sentinal_head.set_next_ptr(node);
  }
  return;
}

void List_double_ptr_Int::pop_back()  {
  if(empty()) {
  return;
  } else if (this->size() == 1) {
    Node *temp1 = sentinal_head.get_next_ptr();
    sentinal_head.set_next_ptr(NULL);
    sentinal_tail.set_prev_ptr(NULL);
    delete temp1;
    --list_size;
  }
  else {
    Node *temp1 = sentinal_tail.get_prev_ptr();
    Node *temp2 = temp1->get_prev_ptr();
    temp2->set_next_ptr(&sentinal_tail);
    sentinal_tail.set_prev_ptr(temp2);
    delete temp1;
    --list_size;

  }
}

void List_double_ptr_Int::pop_front()  {
  if(empty()) {
  return;
  } else if(this->size() == 1) {
    pop_back();
  } else {
    Node *temp1 = sentinal_head.get_next_ptr();
    Node *temp2 = temp1->get_next_ptr();
    sentinal_head.set_next_ptr(temp2);
    temp2->set_prev_ptr(&sentinal_head);
    delete(temp1);
    --list_size;

  }
}

