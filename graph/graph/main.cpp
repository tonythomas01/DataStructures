#include <iostream>
#include "graph.h"
#include<string>
#include<fstream>
#include <cstdlib>

using namespace std;

int main() {
    int x,y;
    string option;
    fstream ofile;
    ofile.open("graph.dot" );
    ofile.open("graphbfs.dot" );
    if ( !ofile )  {
      cout<<"\n Cant open file ";
    } else {
    Graph g1(0);//undirected graph
    cout<<" Enter your command ( eg: insert 2 4 , delet_vertex 2, print )"<<endl;
    do {
    cin>>option;
        if ( option == "insert" ) {
          cin>>x>>y;
          g1.insert(x,y);
        } else if( option == "print" )  {
          g1.print();
        } else if ( option == "print_dot" ){
          g1.print_dot(file);
          file.close();
          system( "xdot graph.dot");
        } else if(c=="delete_edge") {
          cin>>x>>y;
	   g1.delete_edge(x,y);
        } else if(c=="delete_vertex") {
           g1.delete_vertex(x);
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
