//
// Created by souls on 05/05/2020.
//

#include "../../include/node/Type.h"

Type::Type(Indexer<Symbol> &tokens): Node(tokens), value(0) {
}

Type::~Type() {
    delete value;
}

void Type::construct() {
    value = new string(current()->getToken());
    indexer.next();
}

const string Type::str(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Type\"," << "\n" << indent
         << "\"value\": " << *value << "\n" << backIndent << "}";
    return repr.str();
}

string *Type::getValue() const {
    return value;
}
