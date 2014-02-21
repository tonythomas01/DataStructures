#include "Tokenizer.h"
#include <iostream>
#pragma once

template <class Typename>

Token <Typename> Tokenizer <Typename>::get_token()  {
    char ch;
    Typename value;
    while(in.get(ch) && ((ch == ' ') || (ch == '\t')) );
    if (in.good())  {
        switch(ch)  {
        case '^' : return EXP;
        case '/' : return DIV;
        case '*' : return MULT;
        case '+' : return PLUS;
        case '-' : return MINUS;
        case '(' : return LPAREN;
        case ')' : return RPAREN;
        case '\n': return EOL;
        default:
            in.putback(ch);
            if(in>>value)   {
                return Token <Typename> (VALUE, value);
            } else  {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                return UNKNOWN;
            }
        }
    }
    return EOL;
}

template <class Typename>
void Tokenizer<Typename>::clear() {
    in.clear();
}
