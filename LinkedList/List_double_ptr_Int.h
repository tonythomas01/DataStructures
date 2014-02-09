#ifndef LIST_DOUBLE_PTR_INT_H
#define LIST_DOUBLE_PTR_INT_H
#include "Node.h"
#include "Iterator_Node.h"

using namespace std;

class List_double_ptr_Int
{
  private:
    Node sentinal_head;
    Node sentinal_tail;
    size_t list_size;
    int data;
    Node * next;
    Node * prev;
  public:
    List_double_ptr_Int(): sentinal_head(), sentinal_tail(), list_size() {}
    typedef Iterator_Node iterator;
    iterator begin()  {
      return iterator (sentinal_head.get_next_ptr());
    }
    iterator end()  {
      return iterator(&sentinal_tail);
    }
    void print_reverse();
    void push_front(const int &d);
    void push_back(const int &d);
     bool empty()  { return (list_size == -1);}
     int size() {return list_size;}
    void pop_back();
    void pop_front();

     friend class Iterator_Node;
  protected:


};
#include "List_double_ptr_Int.cpp"

#endif // LIST_DOUBLE_PTR_INT_H
