//
// Created by souls on 04/05/2020.
//

#include "../include/AST.h"

AST::AST(Indexer<Symbol>* tokens) : Node(tokens), instructions(0) {
}

AST::~AST() {
   delete instructions;
}

void AST::construct() {
    instructions = new Instructions(indexer);
    instructions->construct();
}

const string AST::json(unsigned int indentSize) const {
    return __cxx11::string();
}

ErrorHandler& AST::getErrorHandler() const {
    return errorHandler;
}

Instructions *AST::getInstructions() const {
    return instructions;
}
