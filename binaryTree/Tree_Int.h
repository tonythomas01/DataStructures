#pragma once
#include<stdlib.h>
#include<iostream>
#include "Node.h"


class Tree_Int
{
    private:

    Node<int>* root;
    size_t tree_size;
    public:
    Tree_Int();
    void insert (int x);
    Node<int>* get_root() const;
    size_t size() const;
    bool empty() const;
    bool is_left_child (Node<int>* node);
    bool is_left_child (int value);
    bool is_leaf(Node<int>* node);
    bool is_leaf(int value);
/*    void inorder (Node<int> *node_ptr, ostream& out = cout) const;
    void inorder(ostream& out = cout) const;
*/

};
#include "Tree_Int.cpp"
