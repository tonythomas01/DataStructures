#include <iostream>
#include<vector>
#include"Max_Heap.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int ints[]= { 20,30,10,9,8,7,6,11,9,17,18,19};
    vector<int> v(ints, ints + (sizeof(ints)/ sizeof(int)) );

    Max_Heap<int> heap_1(v);
    heap_1.levelorder_traversal();
    heap_1.pop_heap();
    heap_1.levelorder_traversal();
    heap_1.pop_heap_without_delete();
    heap_1.levelorder_traversal();
    cout<<heap_1.height();
    heap_1.print_tree();





    return 0;
}
