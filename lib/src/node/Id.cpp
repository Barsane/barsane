//
// Created by souls on 05/05/2020.
//



#include "../../include/node/Id.h"

Id::Id(Indexer<Symbol> &tokens) : Node(tokens), name(0) {
}

Id::~Id() {
    delete name;
}

void Id::construct() {
    name = new string(current()->getToken());
    indexer.next();
}

const string Id::str(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Id\","
         << "\n" << indent
         << "\"name\": " << "\"" << *name << "\""
         << "\n" << backIndent << "}";
    return repr.str();
}
