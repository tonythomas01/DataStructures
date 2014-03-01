#pragma once
#include<stdlib.h>
#include<iostream>


template <class Type>
class Node {
    public:
    Type data;
    Node* right;
    Node* left;
    Node();
    Node(Type d);
    Type get_data();
    Node* get_left() {return left; }
    Node* get_right() {return right; }
    void set_data( Type x) { data =x; }
    Node* set_left( int d ) { right = d; return; }
    Node* set_right( int d ) { left =d; return; }
};

#include "Node.cpp"

