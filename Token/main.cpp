#include <iostream>
#include "stack.h"
#include<stdlib.h>
#include "Tokenizer.h"

using namespace std;

   /* Program entry point. */
int main() {
	Stack< Token<int > > stk;
	Tokenizer<int> tokenizer(cin);
	bool err_flag = false;
	while(1){
	    Stack< Token<int > > stk;
        Tokenizer<int> tokenizer(cin);
		cout << "Enter expression: ";
		cout.flush();
		Token<int> curr_token = tokenizer.get_token();
		/* Read tokens until end of line. */
		while(curr_token.get_type() != EOL) {
			if(curr_token.get_type() == LPAREN) {
				stk.push(curr_token);
			}
			else if(curr_token.get_type() == RPAREN) {
				if(stk.empty()){
					cerr << "Unbalanced right parenthesis" << endl;
					err_flag = true;
					cin.ignore(1000, '\n');
					break;
				}
				else{
					/* Remove a corresponding left
					 * parenthesis from the stack.
					 */
					stk.pop();
				}
			}
			else if(curr_token.get_type() == UNKNOWN) {
				cerr << "Parse Error" << endl;
				err_flag = true;
				break;
			}
			/* Get the next token. */
			curr_token = tokenizer.get_token();
		} /* while. */
		if(! err_flag){
			cout << (stk.empty() ?
					"Equal number of LPAREN & RPAREN"
					:"Unbalanced left parenthesis")
				<< endl;
		}
		err_flag = false, tokenizer.clear();
	}
	return EXIT_SUCCESS;
}


