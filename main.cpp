#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include "List_Int.h"
#include "Node.h"
#include<cassert>
#include "Iterator_Node.h"

using namespace std;

int main()
{
    List_Int l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.print_list();
    l1.pop_back();
    cout<<"\n";
    l1.print_list();
    cout<<"\n Popping front \n";
    l1.pop_front();
    l1.print_list();
//    cout<<"\n Clearing the queue";
//    l1.clear();
    cout<<"\n";
    List_Int::iterator j = l1.end();
    l1.insert(l1.begin(), 20);
    l1.push_back(30), l1.push_back(40);
    cout << "Before: ";
    l1.print_list();
    j = l1.begin();
    j++, j++;
    cout << *j << endl;
    l1.print_list();
    List_Int::iterator i1 = l1.begin(), i2 = l1.begin();
    i1++, i2++, i2++, i2++;
    cout << "i1 points to: " << *i1 << endl;
    cout << "i2 poinst to: " << *i2 << endl;
    l1.erase(i1, i2);
    //l1.erase(i2, i1);
    l1.print_list();
    List_Int::iterator i = l1.begin();
    //List_Int::iterator i; /* Error. */
    //i--; /* Error. */
    //i->; /* Error. */
    return EXIT_SUCCESS;


}
