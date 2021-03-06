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
        void insert( int a, int b);
        void print();
        void delete_vertex(int a);
        void delete_edge( int a, int b);
        void BFS_visit(int vertex, ostream& out );
	void print_dot(ostream& out);
        Graph(): graph_type(0) {}
        Graph( bool b) : graph_type(b)  {}
    private:
	map<int,set<int> > data;
	map < int, set<int> > databack;
        bool graph_type;
};

#include "graph.cpp"
