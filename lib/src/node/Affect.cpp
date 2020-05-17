//
// Created by souls on 05/05/2020.
//


#include "../../include/node/Affect.h"


Affect::Affect(Indexer<Symbol>* tokens) : Node(tokens), id(0), expression(0) {
}

Affect::~Affect() {
    delete id;
    delete expression;
}

void Affect::construct() {
    // id
    id = new Id(indexer);
    id->construct();

    // "="
    if (validate(current()->isAssignment(), "Expected '=' at the end of id")) {
        // expression
        expression = new Expression(indexer);
        expression->construct();
    }

    // ";"
    validate(current()->isSemiColon(), "Expected ';' at the end of affectation");
}

const string Affect::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Affect\"," << "\n" << indent
         << "\"id\": " << id->json(indentSize + 1) << ",\n" << indent
         << "\"expression\": " << expression->json(indentSize + 1)
         << "\n" << backIndent << "}";
    return repr.str();
}

Id *Affect::getId() const {
    return id;
}

Expression *Affect::getExpression() const {
    return expression;
}
