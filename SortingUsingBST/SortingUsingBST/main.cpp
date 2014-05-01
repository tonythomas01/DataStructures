//Input is given from a text file
// Program to print the same in ascending order
#include<iostream>
#include"tree_int.h"
#include<fstream>
using namespace std;

int main()
{
    Tree_Int t1;
    int inp;
    char ch;
    fstream file;
    file.open( "input.txt" );
    if ( file ) {
        while( file>>ch )  {
          inp  = ch - '0';
          t1.insert(inp);
        }
    } else {
      cout<<"\n Cant open file";
    }

    //write result to other file
    file.close();
    fstream fileout;
    fileout.open( "graph.dot");
    if ( fileout )  {
      fileout << "digraph G { "<<endl;
      t1.inorder_traversal(fileout);
      fileout<<"NULL;"<<endl;
      fileout<< "}";
    } else {
      cout << "\n Cant open";
    }
    //cout << "Hello world!" << endl;
    return 0;
}
