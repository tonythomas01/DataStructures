#pragma once
#include<vector>
#include<iostream>
#include<math.h>
#include<cassert>
#include<iomanip>

using namespace std;

template<class type>
class Max_Heap {
    private:
    vector<type> data;
   int heap_size;
    void heapify_down(size_t index);
    void heapify_up(size_t index);
    void make_heap();


    public:
    void pop_heap_without_delete();
    Max_Heap( typename vector<type>::iterator v_begin, typename vector<type>::iterator v_end );
    Max_Heap(vector<type> v);
    void push_heap(type value);
    void pop_heap();
    int height() const {
        return int ( log(double( heap_size)) / log(2.0) );
    }
    type find_max() const{
        return peek();
    }
    size_t size() const;
    bool empty() const {
        return ( heap_size==0);
    }
    type peek() const {
        return data[1];
    }
    void levelorder_traversal(ostream& out = cout) const;
    void print_tree(ostream& out = cout) const;

};
#include "Max_Heap.cpp"


