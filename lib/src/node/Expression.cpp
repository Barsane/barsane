//
// Created by souls on 14/05/2020.
//

#include "../../include/node/Expression.h"

Expression::Expression(Indexer<Symbol> *tokens) : Node(tokens) {

}

Expression::~Expression() {

}

void Expression::construct() {

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

