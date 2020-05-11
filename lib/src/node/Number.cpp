//
// Created by souls on 05/05/2020.
//

#include "../../include/node/Number.h"


Number::Number(Indexer<Symbol>* tokens): Node(tokens), integer(0), real(0), type(NumberType::UNDEFINED) {
}

Number::~Number() {
    delete integer;
    delete real;
}

void Number::construct() {
    evaluate();
    indexer->next();
}

const string Number::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Number\","
         << "\n" << indent
         << "\"value\": ";

    switch(type) {
        case NumberType::INTEGER:
            repr << *integer << ",\n" << indent
                 << "\"type_value\": " << "\"INTEGER\""
                 << "\n" << backIndent << "}";
            break;
        case NumberType::REAL:
            repr << *real << ",\n" << indent
                 << "\"type_value\": " << "\"REAL\""
                 << "\n" << backIndent << "}";
            break;
        default:
            repr << "null" << ",\n" << indent
                 << "\"type_value\": " << "\"UNDEFINED\""
                 << "\n" << backIndent << "}";
    }
    return repr.str();
}

int *Number::getInteger() const {
    return integer;
}

float *Number::getReal() const {
    return real;
}

NumberType::type Number::getType() const {
    return type;
}

void Number::evaluate() {
    str key(current()->getToken());
    if (key.isNumeric()) {
        string value = key.value();
        string::iterator it = find(value.begin(), value.end(), '.');
        if (it == value.end()) {
            integer = new int();
            istringstream(value) >> *integer;
            type = NumberType::INTEGER;
        } else {
            real = new float();
            istringstream(value) >> *real;
            type = NumberType::REAL;
        }
    }
}
