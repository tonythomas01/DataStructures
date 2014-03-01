#include <iostream>
#include "Tree_Int.h"

using namespace std;

int main()
{
    Tree_Int t1;
    t1.insert(10);
    cout<<"\n The current size of tree is :"<<t1.size();
    cout<<"\n";
    t1.insert(20);
    cout<<"\n The current size of tree is :"<<t1.size();
    t1.insert(50);
    t1.insert(5);
    cout<<"\n The current size of tree is :"<<t1.size();
    cout<<"\n";
    cout<<t1.get_root()->right->get_data();

    return 0;
}
