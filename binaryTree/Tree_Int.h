#pragma once
#include<stdlib.h>
#include<iostream>
#include "Node.h"
using namespace std;

class Tree_Int
{
    private:

    Node<int>* root;
    size_t tree_size;
    public:
    Tree_Int();
    void insert (int x);
    Node<int>* get_root();
    size_t size() const;
    bool empty() const;
    bool is_left_child (Node<int>* node);
    bool is_left_child (int value);
    bool is_leaf(Node<int>* node);
    bool is_leaf(int value);
    void inorder (Node<int> *node_ptr, ostream& out );
    void inorder(ostream& out);

    void search( int value );
    Node<int>* search_helper( Node<int>* ptr, int value );

};
#include "Tree_Int.cpp"
