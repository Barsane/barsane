//
// Created by souls on 04/05/2020.
//

#include "../include/AST.h"

AST::AST(Indexer<Symbol> &tokens)
    : Node(tokens), declarations(0), affects(0), builtins(0) {
}

AST::~AST() {
    delete declarations;
    delete affects;
    delete builtins;
}

void AST::construct() {
    while (!indexer.end()) {
        switch (current()->getType()) {
            case ID:
                buildNodeStartWithId();
                break;
            case PRINT:
                buildBuiltins();
                break;
            default:
                Error* error = new Error(SYNTAX_ERROR, "Unrecognized syntax",
                        current()->getLine(), current()->getColon());
                errorHandler.add(error);
                indexer.next();
        }
    }
}

const string AST::str(unsigned int indentSize) const {
    stringstream repr;

    repr << "======================== Abstract Syntax Tree (AST) ========================" << endl;
    if (declarations) {
        repr << "\"Declarations\": " << declarations->str(indentSize);
    }

    if (affects) {
        if (declarations)
            repr << ",\n";
        repr << "\"Affects\": "<< affects->str(indentSize);
    }

    if (builtins) {
        if (declarations || affects)
            repr << ",\n";
        repr << "\"Builtins\": " << builtins->str(indentSize);
    }

    repr << endl;
    repr << "============================================================================" << endl;
    return repr.str();
}

Declarations *AST::getDeclarations() const {
    return declarations;
}

Affects *AST::getAffects() const {
    return affects;
}

Builtins *AST::getBuiltins() const {
    return builtins;
}

ErrorHandler& AST::getErrorHandler() const {
    return errorHandler;
}

void AST::buildNodeStartWithId() {
    // id
    indexer.next();

    // Check if declaration
    if (!indexer.end() && current()->isColon()) {
        indexer.back();
        declarations = new Declarations(indexer);
        declarations->construct();
        return;
    }

    // Check if assignment
    if (!indexer.end() && current()->isAssignment()) {
        indexer.back();
        affects = new Affects(indexer);
        affects->construct();
    }
}

void AST::buildBuiltins() {
     builtins = new Builtins(indexer);
     builtins->construct();
}
