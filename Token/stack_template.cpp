#include "stack.h"
using namespace std;

template <class type>
void  Stack <type>::push(const value_type& x)	{
	if(top_of_stack == stack_size - 1)	{
		throw overflow_error("Stack Full");
		}
	data[++top_of_stack]=x;
	return;
	}

template <typename type>
void Stack<type>::pop() {
	if ( top_of_stack == -1)	{
		throw underflow_error("Stack underflow");
		}
	--top_of_stack;
	return;
	}

template <class type>
ostream& operator<< (ostream& out, const Stack<type>& s)	{
	for(typename Stack<type>::size_type i = s.size()-1; i!=-1; i-- )	{
		out<<"+++++++ "<< "\n";
		out<<" "<< s.data[i]<<"|"<< (( i == s.size()-1) ? "<--top" : " ") <<endl;
		}
	if(s.size()!= 0 )	out<<"+++++++ " <<endl;
		else {
		out<<" STACK EMPTY " <<endl;
		}
	return out;
}


