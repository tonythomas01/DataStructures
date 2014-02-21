#include <iostream>
#include "stack.h"
#include "Tokenizer.h"
#include "Token.h"
#include <stdio.h>

using namespace std;

int main()
{
    while (1)   {
    typedef float data_type;
    typedef Token<data_type> token_type;
    Stack<token_type> stk;
    Tokenizer<data_type> tokenizer(cin);
    bool err_flag;
    token_type op1;
    token_type op2;
    data_type ans;
    token_type finans;

    cout << "Enter expression: ";
    cout.flush();
    Token<float> curr_token = tokenizer.get_token();
    while(curr_token.get_type() != EOL) {
        switch(curr_token.get_type())  {
        case VALUE:
            stk.push(curr_token);
            break;
        case MULT:
        case DIV:
        case PLUS:
        case MINUS:
        case EXP:
          if(stk.size() >= 2)  {
              /*Ineed to get the 2 items out of the stack*/
              op1 = stk.top();
              stk.pop();
              op2 = stk.top();
              stk.pop();
              /* Now to find the result */
              if( curr_token.get_type() == MULT)  {
                  ans = op1.get_value() * op2.get_value();
              } else if (curr_token.get_type() == DIV)  {
                  ans = (op2.get_value() / op1.get_value());
              } else if (curr_token.get_type() == PLUS)  {
                  ans = op1.get_value() + op2.get_value();
              } else if (curr_token.get_type() == MINUS)  {
                  ans = op2.get_value() - op1.get_value();
              } else if (curr_token.get_type() == EXP)  {
                  ans = op1.get_value() * op2.get_value();
              } else {
                  ans = 0;
              }
              stk.push(Token <data_type> (VALUE, ans));
        } else  {
            err_flag =true;
        }
        break;
        case UNKNOWN:
          cerr<< "Parsing error !" << "\n";
          break;
        } if (err_flag) break;
        curr_token = tokenizer.get_token();
      }/*while close*/
      if ( !err_flag ) {
            if ( stk.size() == 1 )  {
              finans = stk.top();
              cout<< finans.get_value()<< endl;
            }
      } else {
            tokenizer.clear();
            cin.ignore(1000, '\n');
            cerr << " Error " << endl;
      }
    }
return EXIT_SUCCESS;
}
