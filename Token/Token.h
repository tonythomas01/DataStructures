#pragma once

enum Token_Type {
       EOL,
       VALUE,
       LPAREN,
       RPAREN,
       PLUS,
       MINUS,
       DIV,
       MULT,
       EXP,
       UNKNOWN
};

template <class Typename>
class Token
{
public:
    Token_Type token_type;
    Typename token_value;
    Token (Token_Type tt = EOL, const Typename& val = 0):token_type(tt), token_value(val){ }
    Token_Type get_type()const;
    const Typename& get_value()const;
};

#include "Token.cpp"
