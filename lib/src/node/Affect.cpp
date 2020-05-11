//
// Created by souls on 05/05/2020.
//


#include "../../include/node/Affect.h"


Affect::Affect(Indexer<Symbol>* tokens) : Node(tokens), id(0) {
}

Affect::~Affect() {
    delete id;
}

void Affect::construct() {
    // id
    id = new Id(indexer);
    id->construct();

    // =
    if (!indexer->end() && current()->isAssignment())
        indexer->next();
    else {
        // TODO: Handle error
        cout << "Not implemented";
        exit(1);
    }

    // value: operation, string, boolean
    if (!indexer->end() && current()->isValue()) {
        number = new Number(indexer);
        number->construct();
    }

    // Check ";"
    if (!indexer->end() && current()->isSemiColon())
        indexer->next();
}

const string Affect::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Affect\"," << "\n" << indent
         << "\"id\": " << id->json(indentSize + 1) << ",\n" << indent
         << "\"operation\": " << number->json(indentSize + 1)
         << "\n" << backIndent << "}";
    return repr.str();
}

Id *Affect::getId() const {
    return id;
}
