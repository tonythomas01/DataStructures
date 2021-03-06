#pragma once

#include<stdio.h>
#include<iostream>
#include<stdexcept>
#include<stdlib.h>
#include<string>
#include<climits>
#include<fstream>

using std::cout;
using std::endl;
using std::ostream;
using std::size_t;
using std::operator<<;

template <class type> class Stack;
template <class type> ostream& operator<< (ostream& out, const Stack<type>& s);

template <class type>
class Stack {
public:
	typedef size_t size_type;
	typedef type value_type;
private:
	static const size_type stack_size = 10;
	value_type data[stack_size];
	signed int top_of_stack;
public:
	Stack(): top_of_stack(-1)	{}
	bool empty()const {return (top_of_stack == -1); }
	size_type size() const {return (top_of_stack+1);}

	value_type& top()	{ return data[top_of_stack]; }
	const value_type& top() const	{ return data[top_of_stack]; }

	void push( const value_type& x);
	void pop();

	friend ostream& operator<< <type> (ostream& out, const Stack <type>& s);
};


#include "stack_template.cpp"


