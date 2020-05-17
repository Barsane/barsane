//
// Created by souls on 05/05/2020.
//

#include "../../include/node/Print.h"

Print::Print(Indexer<Symbol>* tokens) : Node(tokens), expression(0) {
}

Print::~Print() {
    delete expression;
}

void Print::construct() {

    // "print"
    if (validate(current()->isPrint(), "Expected 'print' keyword.")) {
        // expression
        unsigned int pos = indexer->position();
        if (validate(isExpression(), "Invalid expression.")) {
            indexer->reindex(pos);
            expression = new Expression(indexer);
            expression->construct();
        }
    }

    // ";"
    validate(current()->isSemiColon(),
            "Expected ';' at end of print instruction");
}

const string Print::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    repr << "{\n" << indent
         << "\"type\": \"Print\"," << "\n" << indent
         << "\"expression\": " << expression->json(indentSize + 1)
         << "\n" << backIndent << "}";
    return repr.str();
}


Expression *Print::getExpression() const {
    return expression;
}
