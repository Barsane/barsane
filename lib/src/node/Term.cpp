//
// Created by souls on 13/05/2020.
//

#include "../../include/node/Term.h"

Term::Term(Indexer<Symbol> *tokens) : Node(tokens), factor(0), operator_(0), term(0) {
}

Term::~Term() {
    // Do not delete symbols (operator_)
    // because the destructor base (~Node) is called and that handles
    // this action
    delete factor;
    delete term;
}

void Term::construct() {
    // factor
    if (grantNext(isFactor())) {
        factor = new Factor(indexer);
        factor->construct();
    }

    // "*" | "/"
    if (factor && grantNext(current()->isTermOperator())) {
        operator_ = current();
        indexer->next();

        // term
        term = new Term(indexer);
        term->construct();
    }
}

const string Term::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}

Factor *Term::getFactor() const {
    return factor;
}

Symbol *Term::getOperator() const {
    return operator_;
}

Term *Term::getTerm() const {
    return term;
}
