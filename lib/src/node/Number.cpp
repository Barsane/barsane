//
// Created by souls on 05/05/2020.
//

#include "../../include/node/Number.h"


Number::Number(Indexer<Symbol> &tokens): Node(tokens), integer(0), real(0) {
}

Number::~Number() {
    delete integer;
    delete real;
}

void Number::construct() {
    string value = current()->getToken();
    string::iterator it = find(value.begin(), value.end(), '.');
    if (it == value.end()) {
        integer = new int();
        istringstream(value) >> *integer;
    } else {
        real = new float();
        istringstream(value) >> *real;
    }
    indexer.next();
}

const string Number::str(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Number\","
         << "\n" << indent
         << "\"value\": ";
    if (integer) {
        repr << *integer << "\n" << backIndent << "}";
        return repr.str();
    }

    repr << *real << "\n" << backIndent << "}";
    return repr.str();
}

int *Number::getInteger() const {
    return integer;
}

float *Number::getReal() const {
    return real;
}

