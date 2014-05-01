#pragma once
#include "node.h"
#include<fstream>
#include<iostream>
using namespace std;

class Tree_Int
{
    public:
        Tree_Int():root(NULL),tree_size(0)  {}
        void inorder_traversal(fstream& out);
        void inorder_traversal( Node* node, fstream& out);
        void insert(int d);
    protected:
    private:
        Node* root;
        int tree_size;
};

#include "tree_int.cpp"
