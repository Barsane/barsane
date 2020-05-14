//
// Created by souls on 14/05/2020.
//


#include "../../include/node/String.h"

String::String(Indexer<Symbol> *tokens) : Node(tokens), value(0) {
}

String::~String() {
    delete value;
}

void String::construct() {
    str token = str(current()->getToken());
    string msgError = "Unexpected value: A string must be surrounded by double quote.";
    if (validate(token.isExpression(), msgError)) {
        value = new string();
        *value = token.value();
    }
}

const string String::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}

string* String::getValue() const {
    return value;
}
