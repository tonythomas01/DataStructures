#pragma once


class Node
{
    public:
        Node():left(NULL),right(NULL),data(0) {}
        Node(int d):left(NULL),right(NULL),data(d) {}
        Node* get_left() { return left; }
        Node* get_right() { return right; }
        int get_data()  { return data;}
        void set_left(Node* ptr) { left = ptr; }
        void set_right(Node* ptr) { right = ptr; }
    protected:
    private:
        Node* left;
        Node* right;
        int data;
};

