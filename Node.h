#pragma once


class Node
{
    public:
        Node();
        Node(int x);
        int get_data() { return data; }
        void set_data(int val) { data = val; }
        Node* get_next_ptr() { return next; }
        void set_next_ptr(Node *val) { next = val; return; }
        int data;
        Node *next;
        friend class Iterator_Node;
};
#include "Node.cpp"
