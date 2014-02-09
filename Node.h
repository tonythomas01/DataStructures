#pragma once


class Node
{
    public:
        Node();
        Node(int x);
        int get_data() { return data; }
        void set_data(int val) { data = val; }
        Node* get_next_ptr() { return next; }
        Node* get_prev_ptr()  { return prev; }
      void set_next_ptr(Node *ptr) {next= ptr; return;}
      void set_prev_ptr(Node *ptr) {prev= ptr; return;}
        friend class Iterator_Node;
    private:
        int data;
        Node *next;
        Node *prev;



};
#include "Node.cpp"
