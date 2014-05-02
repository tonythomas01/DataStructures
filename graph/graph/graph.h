#pragma once
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<fstream>

using namespace std;
class Graph
{
    public:
        map<int,set<int> > data;
        bool graph_type;
    public:
        void insert( int a, int b);
        void print();
        void delete_vertex(int a);
        void delete_edge( int a, int b);
        void BFS_visit(int vertex, ostream& out );
        Graph(): graph_type(0) {}
        Graph( bool b) : graph_type(b)  {}
    protected:
    private:
};

#include "graph.cpp"
