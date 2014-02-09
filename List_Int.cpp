#include "List_Int.h"
#include "Node.h"
#include "Iterator_Node.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>


using namespace std;

List_Int::List_Int() {
  head=NULL;
  tail=NULL;
  list_size = 0;
  //ctor
}

int List_Int::get_size()    {
    return list_size;
}

void List_Int::push_back(int x) {
  /* The first element */
  Node *ptr = new Node(x);
  list_size++;

  if((head == NULL) && (tail == NULL))    {
    head = tail = ptr;
  }
  /* usual case */
  else {
    tail->set_next_ptr(ptr);
    tail=ptr;
  }
  return;
}

void List_Int::push_front(int x)  {
  Node *ptr = new Node(x);
  /*empty condition*/

  if((head==NULL) && (tail == NULL))  {
    push_back(x);
  }
  else {
    ptr->set_next_ptr(head);
    head= ptr;
  }
}

void List_Int::print_list() {
  if(empty()) {
    cout<<"\n Empty list";
  } else{
    Node *temp=head;
    while(temp!=NULL) {
      cout<<temp->get_data();
      cout<<" --> ";
      temp=temp->get_next_ptr();
    }
  }
}

void List_Int::pop_back() {
  /* if there is only one element */
  if(head == tail)  {
    Node *temp = head;
    --list_size;
    delete temp;
    head = tail = NULL;
  } else {
    Node *next = head;
    Node *prev = NULL;
    while( next != tail )  {
      prev = next;
      next = next->get_next_ptr();
    }
    prev->set_next_ptr(NULL);
    tail = prev;
    delete next;
    list_size--;
  }
}

void List_Int::pop_front()  {
  if(empty())  {
  cout<<"\n Empty Eror";
  return;
  } else  {
    if (head == tail)  {
    Node *tmp = head;
    head = tail = NULL;
    delete tmp;
    --list_size;
  } else {
    Node *tmp = head;
    head = head->get_next_ptr();
    delete tmp;
    --list_size;
    }
  }
}

void List_Int::clear()  {
  while(!empty()) {
    pop_front();
  }
}

List_Int::iterator List_Int::insert (List_Int::iterator position,
const int &x){
/* Create temporary node. */
      Node *temp = new Node(x);
      if(position == this->begin()){
      /* Inserting at the head of the list. */
      temp->set_next_ptr(position.get_node_ptr());
      head = temp;
      ++ list_size;
      }
      else if(position == this->end()){
      /* Inserting at the end of the list. */
      tail->set_next_ptr(temp);
      tail = temp;
      ++ list_size;
      }
      else{
      /* Inserting at the middle of the list. */
      Node *next = head, *prev = NULL;
      while(next != position.get_node_ptr()){
      prev = next;
      next = next->get_next_ptr();
      }
      prev->set_next_ptr(temp);
      temp->set_next_ptr(next);
      ++ list_size;
      }
      return iterator(temp);
}

List_Int::iterator List_Int::erase(List_Int::iterator position) {
  if(position.get_node_ptr() == head) {
    pop_front();
    return this->begin();
  } else if (position.get_node_ptr() == tail) {
    pop_back();
    return this->end();
  } else {
    Node *next = head, *prev = NULL;
    while(next != position.get_node_ptr())  {
      prev =next;
      next = next->get_next_ptr();
    }
    prev->set_next_ptr(next->get_next_ptr());
    delete next;
    --list_size;
    return iterator(prev->get_next_ptr());
  }
}

List_Int::iterator List_Int::erase(iterator first, iterator last) {
  iterator i = first;
  while (i != last) {
    iterator temp =i;
    i = i->get_next_ptr();
    erase(temp);
  }
  return last;
}



