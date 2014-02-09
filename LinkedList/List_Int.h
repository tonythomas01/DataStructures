#ifndef LIST_INT_H
#define LIST_INT_H
#include "Node.h"
#include "List_Int.h"
#include "Iterator_Node.h"

class List_Int
{
    public:
        typedef Iterator_Node iterator;
        typedef const Iterator_Node const_iterator;
        List_Int();
        int get_size();
        void push_back(int x);
        void push_front(int x);
        void print_list();
        void pop_back();
        void pop_front();
        bool empty()  { return (list_size == -1);}
        void clear();
        friend class Iterator_Node;
        iterator begin() {
        return iterator(head);
        }
        iterator end()  {
          if(tail == NULL) return NULL;
          else {
          return iterator(tail->get_next_ptr());
          }
        }
      iterator erase (iterator position);
      iterator erase (iterator first, iterator last);
      iterator insert (iterator position,const int& x);

    protected:
    private:
        Node *head;
        Node *tail;
        int list_size;
};
#include "List_Int.cpp"
#endif // LIST_INT_H
