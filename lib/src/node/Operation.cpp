//
// Created by souls on 13/05/2020.
//

#include "../../include/node/Operation.h"

Operation::Operation(Indexer<Symbol> *tokens) : Node(tokens), term(0), operator_(0), operation(0) {
}

Operation::~Operation() {
    // Do not delete symbol (operator_)
    // because the destructor base (~Node) is called and that handles
    // this action
    delete term;
    delete operation;
}

void Operation::construct() {
    // term
    unsigned int position = indexer->position();
    if (validate(isFactor(), "Expected term expression.")) {
        indexer->reindex(position);
        term = new Term(indexer);
        term->construct();
    }

    // "+" | "-"
    if (term && grantNext(current()->isOperationOperator())) {
        operator_ = current();
        indexer->next();

        if (grantNext(isFactor())) {
            operation = new Operation(indexer);
            operation->construct();
        } else {
            string msg = "Expected operation expression.";
            unsigned int line = current()->getLine();
            unsigned int colon = current()->getColon();
            Error error = Error(UNEXPECTED_TOKEN, msg, line, colon);
            errorHandler.add(error);
            indexer->next();
        }
    }
}

const string Operation::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}

Term *Operation::getTerm() const {
    return term;
}

Symbol *Operation::getOperator() const {
    return operator_;
}

Operation *Operation::getOperation() const {
    return operation;
}