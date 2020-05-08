//
// Created by souls on 05/05/2020.
//

#include "../../include/node/Print.h"

Print::Print(Indexer<Symbol> &tokens) : Node(tokens), id(0) {
}

Print::~Print() {
    delete id;
}

void Print::construct() {
    // print
    indexer.next();

    // TODO: extend to expression
    if (!indexer.end() && current()->isId()) {
        id = new Id(indexer);
        id->construct();
    }

    // Check ";"
    if (!indexer.end() && current()->isSemiColon())
        indexer.next();
}

const string Print::str(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Print\"," << "\n" << indent
         << "\"expression\": " << id->str(indentSize + 1)
         << "\n" << backIndent << "}";
    return repr.str();
}

Id *Print::getId() const {
    return id;
}