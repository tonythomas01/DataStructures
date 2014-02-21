#include "Token.h"

template <class Typename>
Token_Type Token <Typename>::get_type() const {
       return token_type;
}

template <class Typename>
const Typename& Token <Typename>:: get_value() const {
       return token_value;
}
