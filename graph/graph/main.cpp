#include <iostream>
#include "graph.h"
#include<string>
#include<fstream>
#include <cstdlib>

using namespace std;

int main() {
    fstream ofile;
    ofile.open("graphbfs.dot" );
    Graph g(0);//undirected graph
    string c;
    cout<<" Enter your command ( eg: insert 2 4 , delet_vertex 2, print )"<<endl;
    do {
    cin>>c;
        if(c=="insert") {
            int x,y;
            cin>>x>>y;
            g.insert(x,y);
        } else if(c=="print") {
            g.print();
        } else if(c=="delete_edge") {
            int x,y;
            cin>>x>>y;
            g.delete_edge(x,y);
        } else if(c=="delete_vertex") {
            int x;
            cin>>x;
            g.delete_vertex(x);
        } else if ( c == "bfs_dot") {
            int vertex;
            cout<<"\n Enter the start vertex";
            cin>>vertex;
            g.BFS_visit(vertex, ofile);
            system("xdot graphbfs.dot");
        }
         else {
            cout<<"wrong command\n";
        }
    }while(1);
    return 0;
}
