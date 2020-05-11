//
// Created by souls on 05/05/2020.
//

#include "../../include/node/Declaration.h"

Declaration::Declaration(Indexer<Symbol>* tokens) : Node(tokens), id(0), type(0) {
}

Declaration::~Declaration() {
    delete id;
    delete type;
}

void Declaration::construct() {
    // TODO: handle error for else statement
    // id
    id = new Id(indexer);
    id->construct();

    // Check :
    if (!indexer->end() && current()->isColon()) {
        indexer->next();

        // type
        if (!indexer->end() && current()->isType()) {
            type = new Type(indexer);
            type->construct();
        }
    }

    // check ;
    if (!indexer->end() && current()->isSemiColon())
        indexer->next();
}

const string Declaration::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Declaration\","
         << "\n" << indent
         << "\"id\": " << id->json(indentSize + 1) << ",\n" << indent
         << "\"type_id\": " << type->json(indentSize + 1)
         << "\n" << backIndent << "}";
    return repr.str();
}

Id *Declaration::getId() const {
    return nullptr;
}

Type *Declaration::getType() {
    return nullptr;
}
