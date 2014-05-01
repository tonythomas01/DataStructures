#pragma once
#include<iostream>
#include<map>
#include<string>
#include<set>

using namespace std;
class Graph
{
    public:
        map<int,set<int> > data;
        bool graph_type;
        void insert( int a, int b);
        void print();
        void delete_vertex(int a);
        void delete_edge( int a, int b);
        Graph(): graph_type(0) {}
        Graph( bool b) : graph_type(b)  {}
    protected:
    private:
};

#include "graph.cpp"
