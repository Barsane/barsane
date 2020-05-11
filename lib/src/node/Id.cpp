//
// Created by souls on 05/05/2020.
//



#include "../../include/node/Id.h"

Id::Id(Indexer<Symbol>* tokens) : Node(tokens), name(0) {
}

Id::~Id() {
    delete name;
}

void Id::construct() {
    string token = current()->getToken();
    if (validate(current()->isId(),
            "An id must be match this pattern: [a-zA-Z_][a-zA-Z0-9_]*")) {
        name = new string(token);
    }
}

const string Id::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    string strName = "null";
    if (name)
        strName = *name;

    repr << "{\n" << indent
         << "\"type\": \"Id\","
         << "\n" << indent
         << "\"name\": " << "\"" << strName << "\""
         << "\n" << backIndent << "}";
    return repr.str();
}

string *Id::getName() const {
    return name;
}
