//
// Created by souls on 14/05/2020.
//

#include "../../include/node/Expression.h"

Expression::Expression(Indexer<Symbol> *tokens) : Node(tokens), operation(0), boolean(0), stringExpr(0) {
}

Expression::~Expression() {
    delete operation;
    delete boolean;
    delete stringExpr;
}

void Expression::construct() {
    str token = str(current()->getToken());
    if (isFactor()) {
        operation = new Operation(indexer);
        operation->construct();
    } else if (token.isExpression()) {
        stringExpr = new String(indexer);
        stringExpr->construct();
    } else if (token.value() == "true" || token.value() == "false") {
        boolean = new Boolean(indexer);
        boolean->construct();
    } else {
        string msg = "Expected operation, string or boolean.";
        unsigned int line = current()->getLine();
        unsigned int colon = current()->getColon();
        Error error = Error(UNEXPECTED_TOKEN, msg, line, colon);
        errorHandler.add(error);
        indexer->next();
    }
}

const string Expression::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}

Operation *Expression::getOperation() const {
    return operation;
}

String *Expression::getStringExpr() const {
    return stringExpr;
}

Boolean *Expression::getBoolean() const {
    return boolean;
}

