//
// Created by souls on 05/05/2020.
//

#include "../../include/node/Declaration.h"

Declaration::Declaration(Indexer<Symbol>* tokens) : Node(tokens), ids(0), type(0) {
}

Declaration::~Declaration() {
    delete ids;
    delete type;
}

void Declaration::construct() {
    // id
    ids = new Ids(indexer);
    ids->construct();

    // ":" type
    if (validate(current()->isColon(), "Expected ':' at end of id.")) {
        type = new Type(indexer);
        type->construct();
    }

    // ";"
    validate(current()->isSemiColon(), "Expected ';' at end of declaration.");
}

const string Declaration::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Declaration\","
         << "\n" << indent
         << "\"id\": " << ids->json(indentSize + 1) << ",\n" << indent
         << "\"type_id\": " << type->json(indentSize + 1)
         << "\n" << backIndent << "}";
    return repr.str();
}

Ids *Declaration::getIds() const {
    return ids;
}

Type *Declaration::getType() {
    return type;
}
