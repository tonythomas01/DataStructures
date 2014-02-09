#pragma once

#include <iostream>
#include "Token.h"

template <class Typename>
class Tokenizer {
       private:
            std::istream& in;
       public:
            Tokenizer(std::istream& is ) : in(is) {}
            void clear();
            Token <Typename> get_token();
};

#include "Tokenizer.cpp"
